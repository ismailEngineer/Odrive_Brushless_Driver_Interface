import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QPushButton
from PyQt5.QtCore import QSize, Qt
from PyQt5.QtGui import QPixmap
from pathlib import Path


class WindowDriver(QMainWindow):
    def __init__(self):
        super().__init__()
        #print(os.path.dirname(os.path.abspath(__file__)))
        path_ui = str(Path(__file__).parent.parent)+"/ui/"
        uic.loadUi(path_ui + "mainwindow.ui",self)
        path_ressources = str(Path(__file__).parent.parent)+"/ressources/"
        pixmap_odrive = QPixmap(path_ressources + "odrive.png")
        pixmap_odrive = pixmap_odrive.scaledToWidth(300)
        self.logo.setPixmap(pixmap_odrive)

        #self.logo.resize(10,10)





app = QApplication(sys.argv)

window = WindowDriver()
window.show()
app.exec_()