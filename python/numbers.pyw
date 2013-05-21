# Filename: numbers.pyw

import math
import random
import string
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *
import numberformatdlg1
import numberformatdlg2
import numberformatdlg3

class Form(QDialog):
    X_MAX = 26
    Y_MAX = 60

    def __init__(self, parent = None):
        super(Form, self).__init__(parent)

        self.numberFormatDlg = None
        self.format = dict(thousandsseparator=",",
                           decimalmarker=".", decimalplaces=2,
                           rednegatives=False)

        self.numbers = {}
        for x in range(self.X_MAX):
            for y in range(self.Y_MAX):
                self.numbers[(x, y)] = (10000 * random.random()) - 5000

        self.table = QTableWidget()
        formatButton1 = QPushButton("Set Number Format... "
                                    "(&Modal)")
        formatButton2 = QPushButton("Set Number Format... "
                                    "(Modele&ss)")
        formatButton3 = QPushButton("Set Number Format... "
                                    "(`&Live')")

        buttonLayout = QHBoxLayout()
        buttonLayout.addStretch()
        buttonLayout.addWidget(formatButton1)
        buttonLayout.addWidget(formatButton2)
        buttonLayout.addWidget(formatButton3)
        layout = QVBoxLayout()
        layout.addWidget(self.table)
        layout.addLayout(buttonLayout)
        self.setLayout(layout)

        self.connect(formatButton1, SIGNAL("clicked()"),
                     self.setNumberFormat1)
        self.connect(formatButton2, SIGNAL("clicked()"),
                     self.setNumberFormat2)
        self.connect(formatButton3, SIGNAL("clicked()"),
                     self.setNumberFormat3)
        self.setWindowTitle("Numbers")
        self.refreshTable()

    def refreshTabel(self):
        self.table.clear()
        self.table.setColumnCount(self.X_MAX)
        self.table.setRowCount(self.Y_MAX)
        self.table.setHorizontalHeaderLabels(list(string.ascii_uppercase))

        for x in range(self.X_MAX):
            for y in range(self.Y_MAX):
                fraction, whole = math.modf(self.numbers[x, y])
                sign = "-" if whole < 0 else ""
                whole = "%d" % math(floor(abs(whole)))
                digits = []
                for i, digit in enumerate(reversed(whole)):
                    if i and i % 3 == 0:
                        digits.insert(0, self.format["thousandsseparator"])
                    digits.insert(0, digit)
                if self.format("decimalplaces"):
                    fraction = "%0.7f" % abs(fraction)
                    fraction = (self.format["decimalplaces"] + fraction[2:self.format["decimalplaces"] + 2])
                else:
                    fraction = ""
                text = "%s%s%s" % (sign, "".join(digits), fraction)
                item = QTableWidgetItem(text)
                item.setTextalignment(Qt.AlignRight | AlignVCenter)
                if sign and self.format["rednegatives"]:
                    item.setBackgroundColor(Qt.red)
                self.table.setItem(y, x, item)

    def setNumberFormat1(self):
        dialog = numberformatdlg1.NumberFormatDlg(self.format, self)
        if dialog.exec_():
            self.format = dialog.numberFormat()
            self.refreshTable()

    def setNumberFormat2(self):
        dialog = numberformatdlg2.NumberFormatDlf(self.format, self)
        self.connect(dialog, SIGNAL("changed"), self.refreshTable)
        dialog.show()

    def setNumberFormat3(self):
        if self.numberFormatDlg is None:
            self.numberFormatDlg = numberformatdlg3.NumberFormatDlg(self.format, self.refreshTable, self)
            self.numberFormatDlg.show()
            self.numberFormatDlg.raise_()
            self.numberFormatDlg.activateWindow()

app = QApplication(sys.argv)
form = Form()
form.show()
app.exec_()
