import QtQuick 2.15
import QtQuick.Controls 2.15
import MDA.Models 1.0
Item {
    property bool status_media: false
    property bool status_suffle: false
    property bool current_list: false

    id: controlMedia

    width:852
    height:250

    Rectangle {
        id: containerControl
        anchors.fill: parent
        color: "grey"

        SliderMedia{
            id: mySlider
            width_slider: parent.width
            height_slider: 40
            anchors{
                top: parent.top
                topMargin: 15
                left: parent.left
                leftMargin: 60
            }
        }

        ListButtonMedia{
            id: listButton
            anchors{
                top: mySlider.bottom
                horizontalCenter: parent.horizontalCenter
            }
        }

        SpeedMusic{
            id: speedMusic
            anchors{
                top: listButton.bottom
                topMargin: 10
                left: listButton.left
                leftMargin: 20
            }
        }

        VolumeMusic{
            id: volume
            anchors{
                left: speedMusic.right
                leftMargin: 150
                verticalCenter: speedMusic.verticalCenter
            }
        }
    }
}
