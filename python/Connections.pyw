# Filename: Connections.pyw
import sys
from functools import partial
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class Form(QDialog):
    def __init__(self, parent = None):
        super(Form, self).__init__(parent)
        button1 = QPushButton("One")
        button2 = QPushButton("Two")
        button3 = QPushButton("Three")
        button4 = QPushButton("Four")
        button5 = QPushButton("Five")

        self.label = QLabel("Hugo")

        grid = QGridLayout()
        grid.addWidget(button1, 0, 0)
        grid.addWidget(button2, 0, 1)
        grid.addWidget(button3, 0, 2)
        grid.addWidget(button4, 0, 3)
        grid.addWidget(button5, 0, 4)
        grid.addWidget(self.label, 0, 5)
        self.setLayout(grid)

        self.connect(button1, SIGNAL("clicked()"), self.one)
        self.button2callback = partial(self.anyButton, "Two")
        self.connect(button2, SIGNAL("clicked()"), self.button2callback)
        self.button3callback = lambda which = "Three": self.anyButton(which)
        self.connect(button3, SIGNAL("clicked()"), self.button3callback)
        self.connect(button4, SIGNAL("clicked()"), self.clicked)
        self.connect(button5, SIGNAL("clicked()"), self.clicked)
        
    def one(self):
        self.label.setText("You clicked button one")

    def anyButton(self, which):
        self.label.setText("You clicked button %s" % which)

    def clicked(self):
        button = self.sender()
        if button is None or not isinstance(button, QPushButton):
            return 
        self.label.setText("You clicked button %s" % button.text())
            
app = QApplication(sys.argv)
form = Form()
form.show()
app.exec_()
