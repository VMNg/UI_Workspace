import QtQuick 2.15
import QtQuick.Controls
import Climate.Models 1.0

//============================== FRONT TEMPERATURE FUNCTION ==========================

Rectangle {
    id: frontTemp

    property string typeTemp

    color: "#0f0f0f"
    width: 248
    height: 200

    /* Animation when hold */
    PropertyAnimation {
        id: holdScaleAnimation
        property: "scale"
        to: 0.9
        duration: 100
    }
    /* Animation when releasing */
    PropertyAnimation {
        id: releaseScaleAnimation
        property: "scale"
        to: 1.0
        duration: 100
    }

    /*Display the decrease temperature button*/
    Rectangle {
        id: decreaseTemp

        width: 65
        height: 60
        color: "#0f0f0f"
        anchors.top: frontTemp.bottom
        anchors.horizontalCenter: frontTemp.horizontalCenter

        Image {
            source: "qrc:/image/down.png"
            width: 100
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        SequentialAnimation on scale {
            id: decreaseTempAnimation
            PropertyAnimation { to: 0.9; duration: 100 }
            PropertyAnimation { to: 1.0; duration: 100 }
            running: false
        }

        MouseArea {
            id: mDecreaseTemp

            anchors.fill: decreaseTemp
            acceptedButtons: Qt.LeftButton

            onClicked: {
                if(frontTemp.typeTemp === "main"){
                    FunctionModel.setTemperature(FunctionModel.temperature - 1)
                }
                else{
                    FunctionModel.setTemperatureSup(FunctionModel.temperatureSup - 1)
                }
                decreaseTempAnimation.start()
            }
            onPressAndHold: {
                holdScaleAnimation.target = decreaseTemp
                holdScaleAnimation.start()
                decreaseTempTimer.start()
            }
            onReleased: {
                releaseScaleAnimation.target = decreaseTemp
                releaseScaleAnimation.start()
                decreaseTempTimer.stop()
            }
        }
        Timer {
            id: decreaseTempTimer

            interval: 200
            repeat: true
            running: false

            onTriggered: {
                if(frontTemp.typeTemp === "main"){
                    FunctionModel.setTemperature(FunctionModel.temperature - 2)
                }
                else{
                    FunctionModel.setTemperatureSup(FunctionModel.temperatureSup - 2)
                }
            }
        }
    }

    /*Display the increase temperature button*/
    Rectangle {
        id: increaseTemp

        width: 65
        height: 60
        color: "#0f0f0f"
        anchors.bottom: frontTemp.top
        anchors.horizontalCenter: frontTemp.horizontalCenter

        Image {
            source: "qrc:/image/up.png"
            width: 100
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        SequentialAnimation on scale {
            id: increaseTempAnimation
            PropertyAnimation { to: 0.9; duration: 100 }
            PropertyAnimation { to: 1.0; duration: 100 }
            running: false
        }
        MouseArea {
            id: mIncreaseTemp

            anchors.fill: increaseTemp
            acceptedButtons: Qt.LeftButton

            onClicked: {
                if(frontTemp.typeTemp === "main"){
                    FunctionModel.setTemperature(FunctionModel.temperature + 1)
                }
                else{
                    FunctionModel.setTemperatureSup(FunctionModel.temperatureSup + 1)
                }
                increaseTempAnimation.start()
            }
            onPressAndHold: {
                holdScaleAnimation.target = increaseTemp
                holdScaleAnimation.start()  /
                increaseTempTimer.start()
            }
            onReleased: {
                releaseScaleAnimation.target = increaseTemp
                releaseScaleAnimation.start()
                increaseTempTimer.stop()
            }
        }
        Timer {
            id: increaseTempTimer

            interval: 200
            repeat: true
            running: false

            onTriggered: {
                if(frontTemp.typeTemp === "main"){
                    FunctionModel.setTemperature(FunctionModel.temperature + 2)
                }
                else{
                    FunctionModel.setTemperatureSup(FunctionModel.temperatureSup + 2)
                }
            }
        }
    }
}
