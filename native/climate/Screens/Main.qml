import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import Climate.Models 1.0

Window {
    visible: true
    Rectangle {
        id: climate
        anchors.fill: parent
        color: "#1E3A5F"

        /*Display front temperature */
        Temperature {
            id: mainSeatTemp
            typeTemp : "main"
            Text {
                text: FunctionModel.temperature + "°"
                font.pixelSize: 125
                font.weight: Font.ExtraLight
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Noto Sans"
                font.capitalization: Font.MixedCase
                font.letterSpacing: -13
                anchors.centerIn: parent
                width: 155
                height: 155
                color: "orange"
            }

            anchors {
                right: fanSpd.left
                top: parent.top
                rightMargin: 165
                topMargin: 125
            }
        }

        /*Display rear temperature */
        Temperature {
            id: supSeatTemp
            typeTemp : "sup"
            Text {
                text: FunctionModel.temperatureSup + "°"
                font.pixelSize: 125
                font.weight: Font.ExtraLight
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Noto Sans"
                font.capitalization: Font.MixedCase
                font.letterSpacing: -13
                anchors.centerIn: parent
                width: 155
                height: 155
                color: "orange"
            }
            anchors {
                left: fanSpd.right
                top: parent.top
                leftMargin: 165
                topMargin: 125
            }
        }

        /*Display fan speed */
        Fan {
            id: fanSpd
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }

        }

        /*Display AC functions*/
        Functions {
            id: functions
            anchors {
                right: fanSpd.left
                top: mainSeatTemp.bottom
                rightMargin: 90
                topMargin: 130
            }
        }
    }
}
