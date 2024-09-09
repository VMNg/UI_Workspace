import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: tabButton
    property bool isCurrentItem: false

    implicitWidth: 360  // Assuming 1080 width divided by 3 buttons
    implicitHeight: 50

    background: Rectangle {
        color: "transparent"
        Rectangle {
            width: parent.width
            height: 3
            anchors.bottom: parent.bottom
            color: tabButton.isCurrentItem ? "#8e44ad" : "transparent"
        }
    }

    contentItem: Text {
        text: tabButton.text
        font.pixelSize: 18
        font.bold: tabButton.isCurrentItem
        color: tabButton.isCurrentItem ? "#8e44ad" : "#7f8c8d"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: tabButton.clicked()
    }
}
