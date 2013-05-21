# Filename: numberformatdlg1.pyw

from PyQt4.QtCore import *
from PyQt4.QtGui import *

class NumberFormatDlg(QDialog):

    def __init__(self, format, parent = None):
        super(NumberFormatDlg, self).__init__(parent)

        thousandsLabel = QLabel("&Thousands separator")
        self.thousandsEdit = QLineEdit(format["thousandsseparator"])
        thousandsLabel.setBuddy(self.thousandsEdit)
        decimalMarkerLabel = QLabel("Decimal &marker")
        self.decimalMarkerEdit = QLineEdit(format["decimalmarker"])
        decimalMarkerLabel.setBuddy(self.decimalMarkerEdit)
        decimalPlacesLabel = QLabel("&Decimal places")
        self.decimalPlacesSpinBox = QSpinBox()
        decimalPlacesLabel.setBuddy(self.decimalPlacesSpinBox)
        self.decimalPlacesSpinBox.setValue(format["decimalplaces"])
        self.redNegativesCheckBox = QCheckBox("&Red negative numbers")
        self.redNegativesCheckBox.sefChecked(format["rednegatives"])
        
        buttonBox = QDialogButtonBox(QDialogButtonBox.Ok | QDialogByttonBox.Cancel)

        self.format = format.copy()

        grid = QGridLayout()
        grid.addWidget(thousandsLabel, 0, 0)
        grid.addWidget(self.thousandsEdit, 0, 1)
        grid.addWidget(decimalMarkerLabel, 1, 0)
        grid.addWidget(self.decimalMarkerEdit, 1, 1)
        grid.addWidget(decimalPlacesLabel, 2, 0)
        grid.addWidget(self.decimalPlacesSpinBox, 2, 1)
        grid.addWidget(self.redNegativesCheckBox, 3, 0, 1, 2)
        grid.addWidget(buttonBox, 4, 0, 1, 2)
        self.setLayout(grid)

        self.connect(buttonBox, SIGNAL("accepted()"),
                     self, SLOT("accept()"))
        self.connect(buttonBox, SIGNAL("rejected()"),
                     self, SLOT("reject()"))
        self.setWindowTitle("Set Number Format (Modal)")

    def accept(self):
        class ThousandsError(Exception): pass
        class DecimalError(Exception): pass
        Punctuation = frozenset(" ,;:.")

        thousands = unicode(self.thousandsEdit.text())
        decimal = unicode(self.decimalMarkerEdit.text())

        try:
            if len(deciaml) == 0:
                raise DecimalError, ("The decimal marker may not be empty.")
            if len(thousands) > 1:
                raise ThousandsError, ("The thousands separatot may only be empyt or on charcter.")
            if len(decimal) > 1:
                raise DecimalError, ("The decimal marker must be one character.")
            if thousands == decimal:
                raise ThousandsError, ("The thousands separator and the decimal marker must be different.")
            if thousands and thousands not in Punctuation:
                raise ThousandsError, ("The thousands separator must be a punctation symbol.")
            if decimal not in Punctuation:
                raise DecimalError, ("The decimal marker must be a punctuation symbol.")
        except ThousandsError, e:
            raise QMessageBox.warning(self, "Thousands Separator Error", unicode(e))
            self.thousandsEdit.selectAll()
            self.thousandsEdit.setFocus()
            return
        except DecimalError, e:
            QMessageBox.warning(self, "Decimal Marker Error", unicode(e))
            self.decimalMarkerEdit.selectAll()
            self.decimalMarkerEdit.setFocus()

        self.format["thousandsseparator"] = thousands
        self.format["decimalmarker"] = decimal
        self.format["decimalplaces"] = self.decimalPlacesSpinBox.value()
        self.format["rednegatives"] = self.redNegativesCheckBox.isChecked()
        QDialog.accept(self)

    def numberFormat(self):
        return self.format
