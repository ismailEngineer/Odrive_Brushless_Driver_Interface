from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QPushButton
from PyQt5.QtCore import QSize, Qt
import sys


class WindowDriver(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle('Odrive Application')
        button = QPushButton("press here")

        self.setFixedSize(QSize(500,500))
        #self.setMinimumSize(QSize(500,500))
        #self.setMaximumSize(QSize(500,500))

        self.setCentralWidget(button)

app = QApplication(sys.argv)

window = WindowDriver()
window.show()  # IMPORTANT!!!!! Windows are hidden by default.

app.exec()