import QtQuick 2.15
Rectangle {
    id: root
    property bool active:  false
    property bool activeButton : false
    property string sourceFunction
    property string textFunction
    property int clickCount: 0
    signal clicked()

    width: parent.width / 4
    height: parent.height
    color: "#1E3A5F"

    Image {
        id: img

        source: sourceFunction
        height: 60
        width: 60
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        /* Animation when hold */
        PropertyAnimation {
            id: holdScaleAnimation
            target: img
            property: "scale"
            to: 0.9
            duration: 100
        }
        PropertyAnimation {
            id: holdScaleAnimationText
            target: textF
            property: "scale"
            to: 0.9
            duration: 100
        }

        /* Animation when releasing */
        PropertyAnimation {
            id: releaseScaleAnimation
            property: "scale"
            target: img
            to: 1.0
            duration: 100
        }
        PropertyAnimation {
            id: releaseScaleAnimationText
            property: "scale"
            target: textF
            to: 1.0
            duration: 100
        }

        SequentialAnimation on scale {
            id: scaleImg
            PropertyAnimation { to: 0.9; duration: 100 }
            PropertyAnimation { to: 1.0; duration: 100 }
            running: false
        }

        MouseArea {
            anchors.fill: img
            onClicked: {
                if (!activeButton) {
                    root.clickCount += 1
                    active = !active
                    root.clicked()
                } else {
                    scaleImg.start()
                    scaleText.start()
                }
            }
            onPressAndHold: {
                if(activeButton === true){
                    holdScaleAnimation.start()
                    holdScaleAnimationText.start()
                }
            }
            onReleased: {
                if(activeButton === true){
                    releaseScaleAnimation.start()
                    releaseScaleAnimationText.start()
                }
            }
        }
    }
    Text {
        id: textF
        text: textFunction
        anchors.top : img.bottom
        font.pixelSize: 20
        anchors.horizontalCenter: img.horizontalCenter
        color: activeButton ? "white" : (active ? "orange" : "#808080")
        SequentialAnimation on scale {
            id: scaleText
            PropertyAnimation { to: 0.9; duration: 100 }
            PropertyAnimation { to: 1.0; duration: 100 }
            running: false
        }
    }
}

