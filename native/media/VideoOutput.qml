import QtQuick 2.15
import QtQuick.Controls
import RenderVideo 1.0
import MDA.Models 1.0
VideoRender{
    id: videoRender
    property bool isFullScreen: false
    width: 852
    height: 420
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
                    videoRender.width = 852
                    videoRender.height = 420
                    isFullScreen = false
                }else{
                    videoRender.width = 852
                    videoRender.height = 620
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
