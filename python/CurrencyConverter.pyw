# Filename: CurrencyConverter.pyw

import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class Form(QDialog):
    def __init__(self, parent = None):
        super(Form, self).__init__(parent)
        date = self.getdata()
        rates = sorted(self.rates.keys())
        dateLabel = QLabel(date)
        self.fromComboBox = QComboBox()
        self.fromComboBox.addItems(rates)
        self.fromSpinBox = QDoubleSpinBox()
        self.fromSpinBox.setRange(0.01, 10000000.00)
        self.fromSpinBox.setValue(1.00)
        self.toComboBox = QComboBox()
        self.toComboBox.addItems(rates)
        self.toLabel = QLabel("1.00")

        grid = QGridLayout()
        grid.addWidget(dateLabel, 0, 0)
        grid.addWidget(self.fromComboBox, 1, 0)
        grid.addWidget(self.fromSpinBox, 1, 1)
        grid.addWidget(self.toComboBox, 2, 0)
        grid.addWidget(self.toLabel, 2, 1)
        self.setLayout(grid)

        self.connect(self.fromComboBox,
                    SIGNAL("currentIndexChanged(int)"), self.updateUi)
        self.connect(self.toComboBox,
                    SIGNAL("currentIndexChanged(int)"), self.updateUi)
        self.connect(self.fromSpinBox,
                    SIGNAL("valueChanged(double)"), self.updateUi)
        self.setWindowTitle("Currency")

    def updateUi(self):
        to = unicode(self.toComboBox.currentText())
        from_ = unicode(self.fromComboBox.currentText())
        amount = (self.rates[from_] / self.rates[to]) * self.fromSpinBox.value()
        self.toLabel.setText("%0.2f" % amount)

    def getdata(self): # Idea taken from the Python Cookbook
        self.rates = {}
        try:
            date = "Unknow"
            fh = open("fx-seven-day.csv", "r")
            for line in fh:
                if not line or line.find("#") == 0:
                    continue
                fields = line.split(",")
                if line.find("Date ") == 0:
                    date = fields[-1]
                else:
                    try:
                        value = float(fields[-1])
                        self.rates[unicode(fields[0])] = value
                    except ValueError:
                        pass
            fh.close()
            return "Exchange Rates Date: " + date
        except Exception, e:
            fh.close()
            return "Failed to open:\n%s" % e
                        
app = QApplication(sys.argv)
form = Form()
form.show()
app.exec_()
