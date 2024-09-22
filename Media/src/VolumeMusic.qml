import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: volume
    width: 300
    height: 64
    Row{
        spacing: 10
        width: parent.width
        height: parent.height
        Image {
            id: speedMedia
            source: updateImage(mySlider.value)
            width: 64
            height: 64

            MouseArea{
                anchors.fill: parent
                onClicked:{
                    mySlider.value = 0
                    playerControl.setVolume(0)
                }
            }
        }
        Slider{
            id: mySlider
            anchors{
                verticalCenter: speedMedia.verticalCenter
            }

            width: volume.width * 0.83
            from: 0
            value: 50
            to: 100
            stepSize: 1
            background: Rectangle
            {
                x: mySlider.leftPadding
                y: mySlider.topPadding + mySlider.availableHeight / 2 - height / 2
                width: mySlider.availableWidth
                height: 10
                radius: height / 2
                color: "#130f40"

                Rectangle
                {
                    width: mySlider.visualPosition === 0 ? 0 : mySlider.handle.x  + mySlider.handle.width / 2
                    height: 10
                    color: "#7ed6df"
                    radius: height / 2
                }
            }
            handle: Rectangle
            {
                x: mySlider.leftPadding + mySlider.visualPosition * (mySlider.availableWidth - width)
                y: mySlider.topPadding + mySlider.availableHeight / 2 - height/ 2
                implicitHeight: 15
                implicitWidth: 15
                radius: implicitWidth / 2
                color: mySlider.pressed ? "#dff9fb" : "#222f3e"
                border.color: "#1dd1a1"
                border.width: 2
            }
            Text {
                id: current_volume
                text: mySlider.value
                font.bold: true
                anchors{
                    left: parent.right
                    leftMargin: 7
                    verticalCenter: parent.verticalCenter
                }
            }
        }
    }
    Connections {
        target: mySlider
        function onMoved(){
            playerControl.setVolume((mySlider.value)/100)
        }
    }

    function updateImage(volume){
        var sources = "";
        if(0 < volume && volume <= 60){
            sources = "qrc:/iconControlMedia/volume_medium.png";
        }
        else if(volume === 0){
            sources = "qrc:/iconControlMedia/volume_mute.png";
        } else {
            sources = "qrc:/iconControlMedia/volume_high.png";
        }
        return sources;
    }
}
