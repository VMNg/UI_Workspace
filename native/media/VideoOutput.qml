import QtQuick 2.15
import QtQuick.Controls
import RenderVideo 1.0
import MDA.Models 1.0
VideoRender{
    id: videoRender
    property bool isFullScreen: false
    width: 720
    height: 470
    visible: isVideoScreen
    funcModel: FunctionModel
    Image {
        id: button_fullScreen
        width: 64
        height: 64
        visible: isVideoScreen
        source: isFullScreen ? "qrc:/iconControlMedia/minimize-screen.png" : "qrc:/iconControlMedia/full-screen.png"
        anchors{
            right: parent.right
            bottom: parent.bottom
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(isFullScreen){
                    videoRender.width = 720
                    videoRender.height = 470
                    isFullScreen = false
                }else{
                    videoRender.width = 1080
                    videoRender.height = 670
                    isFullScreen = true
                }
            }
        }
    }
    MouseArea{
        width: videoRender.width - 64
        height: videoRender.height - 64
        onClicked:{

        }
    }
}
