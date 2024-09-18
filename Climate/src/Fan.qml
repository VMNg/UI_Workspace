import QtQuick 2.15
import QtQuick.Controls.Basic


//============================== FAN SPEED FUNCTION ==========================

Item {
    id: fan
    width: 160
    height: 492
    ListView {
        id: listView
        anchors.fill: fan
        width: parent.width
        height: parent.height
        interactive: false
        highlightMoveDuration: 100
//        currentIndex: 6  /*(6 or -1)*/
        highlight: Rectangle {
             color: "#00000000"
             border.color: "lightgreen"
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
            background: Item {
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 2
                    color: "white"
                    radius: 5
                    border.width: 1

                    /*Animation when a button is clicked, will be played in the onClicked function*/
                    SequentialAnimation on color {
                      id: chooseFanSpdAnimation
                      ColorAnimation { to: "#0f0f0f"; duration: 100 }
                      ColorAnimation { to: "white"; duration: 100 }
                      running: false
                    }
                }
            }
            flat:true
            width: listView.width
            height: listView.height / 7
            text: model.name
            font.pixelSize: 18

            /*When a button is clicked, move the highlight to the according button*/
            onClicked: {
                listView.currentIndex = model.index;
                listView.forceActiveFocus();
                chooseFanSpdAnimation.start()
            }
        }
    }
}
