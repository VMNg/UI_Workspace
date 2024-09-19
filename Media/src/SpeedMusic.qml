import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 100
    height: 64
    Row{
        spacing: 10
        Image {
            id: speedMedia
            source: "qrc:/iconControlMedia/speedMedia.png"
            width: 64
            height: 64
        }
        ComboBox {
            anchors{
                verticalCenter: speedMedia.verticalCenter
            }
            displayText: "Speed: " + currentText
            currentIndex: 1
            down: true
            model: ListModel {
                id: model
                ListElement { text: "0.5x" }
                ListElement { text: "1.0x" }
                ListElement { text: "2.0x" }
                ListElement { text: "4.0x" }
            }
            onActivated: {
                switch (currentIndex) {
                case 0:
                    playerControl.setPlayBackMedia(0.5);
                    break;
                case 2:
                    playerControl.setPlayBackMedia(2);
                    break;
                case 3:
                    playerControl.setPlayBackMedia(4);
                    break;
                default:
                    playerControl.setPlayBackMedia(1);
                }
            }
        }
    }
}
