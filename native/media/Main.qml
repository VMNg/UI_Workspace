import QtQuick 2.15
import QtQuick.Controls 2.0
import RenderVideo 1.0
import MDA.Models 1.0
Window{
    visible: true
    property bool isVideoScreen: false
    property bool isPauseMusic: true

    Rectangle {
        id: mainScreen
        anchors.fill: parent
        color: "#1e1e1e"

        Rectangle {
            id: centerMusic
            width: 720
            height: 670
            color: "#1e1e1e"
            anchors {
                left: mainScreen.left
                top: mainScreen.top
            }

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
            VideoOutput{
                z: 1;
                anchors{
                    top: centerMusic.top
                    left: centerMusic.left
                }
            }

            // width: 720
            // height: 470
            ScreenWithMusic{
                anchors{
                    top: centerMusic.top
                    left: centerMusic.left
                }
            }
        }
    }
}
