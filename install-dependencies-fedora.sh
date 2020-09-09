#!/bin/bash


sudo dnf update
sudo dnf upgrade
sudo dnf install boost-devel
sudo dnf install opencv opencv-devel
sudo dnf install cpprest-devel
sudo dnf install qt qt-devel qt5 qt5-devel qt5-qtbase qt5-qtbase-devel
sudo dnf install websocketpp-devel
sudo ln -s /usr/bin/qmake-qt5 DesktopApplication/ball_bouncer/qmake
