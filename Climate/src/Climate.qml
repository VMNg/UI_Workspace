import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
// import "AirCon"

Item {
    id: window
    width: 1080
    height: 720
    // clip: true

    Rectangle {
        id: hvacScreen
        // width: 1280 * 2/3
        // height: window.height * 10/ 12
        anchors.fill: parent
        // radius: 20

        /*Display front temperature */
        Temperature_front {
            id: frontTemp
            Text {
                text: settingsHVAC.frontTemperature
                font.pixelSize: 120
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                anchors.centerIn: parent
                width: 155
                height: 155
                color: "#272626"
            }

            anchors {
                right: fanSpd.left
                top: parent.top
                topMargin: 117
                rightMargin: 48
            }
        }

        /*Display rear temperature */
        Temperature_rear {
            Rectangle{
                color: "red"
                anchors.fill: parent
            }

            id: rearTemp
            Text {
                text: settingsHVAC.rearTemperature
                font.pixelSize: 120
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                anchors.centerIn: parent
                width: 155
                height: 155
                color: "#272626"
            }
            anchors {
                left: fanSpd.right
                top: parent.top
                leftMargin: 47
                topMargin: 117
            }
        }

        /*Display fan speed */
        Fan {
            id: fanSpd
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
                verticalCenterOffset: -5
                horizontalCenterOffset: -1
            }

        }

        /*Display AC functions*/
        Functions1 {
            id: fnc1
            anchors {
                right: fanSpd.left
                top: frontTemp.bottom
                rightMargin: 48
                topMargin: 127
            }
        }

        /*Display airflow*/
        Functions2 {
            id: fnc2
            anchors {
                left: fanSpd.right
                top: rearTemp.bottom
                leftMargin: 48
                topMargin: 127
            }

        }
        color: "#0f0f0f"
    }

    // function togglePanelHVAC() {
    //     var targetHeight = (sidePanelHVAC.height === 0) ? hvacScreen.height + 48 : 0;

    //     var animation = Qt.createQmlObject('import QtQuick 2.15; PropertyAnimation {}', sidePanelHVAC);
    //     animation.target = sidePanelHVAC;
    //     animation.property = 'height';
    //     animation.to = targetHeight;
    //     animation.easing.type = Easing.InOutQuad;
    //     animation.duration = 200;
    //     animation.start();
    // }

    // function detogglePanelHVAC() {
    //     var targetHeight = 0;

    //     var animation = Qt.createQmlObject('import QtQuick 2.15; PropertyAnimation {}', sidePanelHVAC);
    //     animation.target = sidePanelHVAC;
    //     animation.property = 'height';
    //     animation.to = targetHeight;
    //     animation.easing.type = Easing.InOutQuad;
    //     animation.duration = 200;
    //     animation.start();
    // }

}
