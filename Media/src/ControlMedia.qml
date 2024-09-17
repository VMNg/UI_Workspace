import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property bool status_media: false
    property bool status_suffle: false
    property bool current_list: false

    id: controlMedia

    width:720
    height:150

    Rectangle {
        id: containerControl
        anchors.fill: parent
        color: "grey"

        SliderMedia{
            width_slider: parent.width
            height_slider: parent.height
            anchors{
                top: parent.top
                topMargin: 15
                left: parent.left
                leftMargin: 60
            }
        }

        ListButtonMedia{
            anchors{
                bottom: parent.bottom
                bottomMargin: 30
                horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
