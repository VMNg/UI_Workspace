import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick 2.4
import Videoplayer 1.0

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

            //width:720
            //height:200
            ControlMedia{
                anchors{
                    bottom: parent.bottom
                }
            }

            // width: 360
            // height: 670
            ListMedia{
                anchors{
                    right: parent.right
                }
            }

            // width: 720
            // height: 470
            ScreenWithMusic{
                id: streamScreen
                visible: false
                anchors{
                    top: centerMusic.top
                    left: centerMusic.left
                }
            }

            // width: 720
            // height: 470
            VideoPlayer{
                id: videoPlayer
                visible: true
                width: 720
                height: 470
                anchors{
                    top: centerMusic.top
                    left: centerMusic.left
                }
            }
        }
    }
}
