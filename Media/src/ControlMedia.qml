import QtQuick 2.15
import PlayerControl 1.0

Item {
    id: controlMedia
    width:720
    height:120

    MediaControl{
        id: playerControl
    }

    Rectangle {
        id: containerControl
        anchors.fill: parent
        color: "grey"
        Row{
            anchors.horizontalCenter: containerControl.horizontalCenter
            anchors.verticalCenter: containerControl.verticalCenter
            spacing: 80

            Image {
                source: "qrc:/iconControlMedia/suffle.png"
                width: 64
                height: 64
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("Click Button!!");
                    }
                }
            }
            Image {
                source: "qrc:/iconControlMedia/rewind-button.png"
                width: 64
                height: 64
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("Click Button!!");
                    }
                }
            }
            Image {
                source: "qrc:/iconControlMedia/play-button-arrowhead.png"
                width: 64
                height: 64
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        playerControl.playClicked();
                    }
                }
            }
            Image {
                source: "qrc:/iconControlMedia/forward-button.png"
                width: 64
                height: 64
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("Click Button!!");
                    }
                }
            }
            Image {
                source: "qrc:/iconControlMedia/play-list.png"
                width: 64
                height: 64
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("Click Button!!");
                    }
                }
            }
        }
    }
}
