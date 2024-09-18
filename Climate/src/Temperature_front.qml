import QtQuick 2.15
import QtQuick.Controls

//============================== FRONT TEMPERATURE FUNCTION ==========================

Rectangle {
    id: frontTemp
    color: "#ffffff"
    border.width: 1
    width: 248
    height: 239

    /*Display the decrease temperature button*/
    Rectangle {
        id: decreaseTemp
        x: 0
        width: frontTemp.width
        height: 70
        color: "#0f0f0f"
        border.width: 1
        anchors.top: frontTemp.bottom
        anchors.topMargin: -1
        anchors.bottomMargin: 1
        radius: 5

        /*Display the icon for the button*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/down.png"
            width: parent.width
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        /*Animation when this button is clicked, the animation will be run in the onClicked function*/
        SequentialAnimation on color {
            id: increaseTempAnimation
            ColorAnimation { to: "white"; duration: 100 }
            ColorAnimation { to: "#33000000"; duration: 100 }
            running: false
        }

        /*Mouse area to allow clicking on the button, allowing the button to change the temperature. The temperature is to be saved into the ini file.
        */
        MouseArea {
            id: mDecreaseTemp
            anchors.fill: decreaseTemp
            acceptedButtons: Qt.LeftButton

            onClicked: {
                settingsHVAC.editTemperatureFront(-1)
                increaseTempAnimation.start()
            }
        }
    }

    /*Display the increase temperature button*/
    Rectangle {
        id: increaseTemp
        width: frontTemp.width
        height: 70
        color: "#0f0f0f"
        border.width: 1
        anchors.bottom: frontTemp.top
        anchors.bottomMargin: -1
        radius: 5

        /*Display the icon for the button*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/up.png"
            width: parent.width
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        /*Animation when this button is clicked, the animation will be run in the onClicked function*/
        SequentialAnimation on color {
            id: decreaseTempAnimation
            ColorAnimation { to: "white"; duration: 50 }
            ColorAnimation { to: "#33000000"; duration: 50 }
            running: false
        }

        /*Mouse area to allow clicking on the button, allowing the button to change the temperature. The temperature is to be saved into the ini file.
        */
        MouseArea {
            id: mIncreaseTemp
            anchors.fill: increaseTemp
            acceptedButtons: Qt.LeftButton
            onClicked: {
                settingsHVAC.editTemperatureFront(+1)
                decreaseTempAnimation.start()
            }
        }
    }
    radius: 5
    gradient: Gradient {
        GradientStop { position: 1; color: "grey" }
        GradientStop { position: 0; color: "white" }
    }
}
