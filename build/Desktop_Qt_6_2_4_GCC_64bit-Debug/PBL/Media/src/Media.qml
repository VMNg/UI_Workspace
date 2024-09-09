import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 1080
    height: 670

    Rectangle {
        id: mainScreen
        anchors.fill: parent
        color: "#1e1e1e"

        Rectangle {
            id: centerMusic
            anchors {
                left: mainScreen.left
                top: mainScreen.top
            }
            width: 720
            height: 670
            color: "yellow"

            ControlMedia{
                anchors{
                    bottom: parent.bottom
                }
            }
        }

        Rectangle {
            id: listMusic
            anchors {
                right: mainScreen.right
                top: mainScreen.top
            }
            width: 360
            height: 670
            color: "black"
        }
    }
}
