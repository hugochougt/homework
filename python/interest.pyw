# Filename: interest.pyw

import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class Interest(QDialog):
    def __init__(self, parent = None):
        super(Interest, self).__init__(parent)
        
        years = self.getYears()
        
        self.principalLabel = QLabel("Principal: ")
        self.principalSpinBox = QDoubleSpinBox()
        self.principalSpinBox.setRange(0, 1000000000) # 看答案后加的
        self.principalSpinBox.setValue(0.00)
        self.principalSpinBox.setPrefix(u"￥ ")
        self.rateLabel = QLabel("Rate: ")
        self.rateSpinBox = QDoubleSpinBox()
        self.rateSpinBox.setRange(0, 100) # 看答案后加的
        self.rateSpinBox.setSuffix(r" %")
        self.yearsLabel = QLabel("Years: ")
        self.yearsComboBox = QComboBox()
        self.yearsComboBox.addItems(years)
        self.amountLabel = QLabel("Amount: ")
        self.amountResult = QLabel("RMB 0.00")
        # amountResult.setPrefix(u"￥")   !AttributeError: 'QLabel' object has no attribute 'setPrefix'
        
        grid = QGridLayout()
        grid.addWidget(self.principalLabel, 0, 0)
        grid.addWidget(self.principalSpinBox, 0, 1)
        grid.addWidget(self.rateLabel, 1, 0)
        grid.addWidget(self.rateSpinBox, 1, 1)
        grid.addWidget(self.yearsLabel, 2, 0)
        grid.addWidget(self.yearsComboBox, 2, 1)
        grid.addWidget(self.amountLabel, 3, 0)
        grid.addWidget(self.amountResult, 3, 1)
        
        self.setLayout(grid)
        self.setWindowTitle("Interest")

        self.connect(self.principalSpinBox, SIGNAL("valueChanged(double)"), self.updateUi)
        self.connect(self.rateSpinBox, SIGNAL("valueChanged(double)"), self.updateUi)
        self.connect(self.yearsComboBox, SIGNAL("currentIndexChanged(int)"), self.updateUi)

    def updateUi(self):
        principal = self.principalSpinBox.value()
        rate = self.rateSpinBox.value()
        years = self.yearsComboBox.currentIndex() + 1
        amount = principal * ((1 + rate / 100.0) ** years)
        self.amountResult.setText("RMB %0.2f" % amount)

    def getYears(self):
        years = ['1 year']
        for year in range(2, 11):
            years.append('{0} years'.format(year))
        return years

app = QApplication(sys.argv)
interest = Interest()
interest.show()
app.exec_()
