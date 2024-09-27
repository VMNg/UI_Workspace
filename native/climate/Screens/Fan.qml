import QtQuick 2.15
import QtQuick.Controls.Basic


//============================== FAN SPEED FUNCTION ==========================

Item {
    id: fan
    width: 140
    height: 530
    ListView {
        id: listView
        anchors.fill: fan
        width: parent.width
        height: parent.height
        interactive: false
        highlightMoveDuration: 100
        highlight: Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#00000000"
            border.color: "orange"
            border.width: 3
            radius: 5
        }

        model: ListModel {
            ListElement {
                name: "5"
            }

            ListElement {
                name: "4"
            }

            ListElement {
                name: "3"
            }

            ListElement {
                name: "2"
            }

            ListElement {
                name: "1"
            }

            ListElement {
                name: "Auto"
            }

            ListElement {
                name: "Off"
            }
        }

        /*Display the amount of button based on the number of list element*/
        delegate: Button {
            anchors.horizontalCenter: parent.horizontalCenter
            background: Item {
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 2
                    color: "#CCCCCC"
                    radius: 5
                    border.width: 1

                    /*Animation when a button is clicked, will be played in the onClicked function*/
                    SequentialAnimation on color {
                      id: chooseFanSpdAnimation
                      ColorAnimation { to: "#0f0f0f"; duration: 100 }
                      ColorAnimation { to: "#CCCCCC"; duration: 100 }
                      running: false
                    }
                    SequentialAnimation on scale {
                        id: chooseFanSpdAnimationScale
                        PropertyAnimation { to: 1.3; duration: 100 }
                        PropertyAnimation { to: 1.0; duration: 100 }
                        running: false
                    }
                }
            }
            flat:true
            // width: listView.width
            width: listView.currentIndex === model.index ? (listView.width * 7/6) : listView.width
            height: listView.currentIndex === model.index ?  (listView.height / 7) : ((listView.height / 7) - 5)
            Text {
                anchors.centerIn: parent
                id: buttonText
                text: model.name
                font.pixelSize: listView.currentIndex === model.index ? 32 : 22
                color: "black"
            }

            /*When a button is clicked, move the highlight to the according button*/
            onClicked: {
                listView.currentIndex = model.index
                listView.forceActiveFocus()
                chooseFanSpdAnimation.start()
                chooseFanSpdAnimationScale.start()
            }
        }
    }
}
