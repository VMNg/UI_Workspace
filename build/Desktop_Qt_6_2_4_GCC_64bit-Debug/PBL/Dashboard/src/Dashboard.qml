import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 1080
    height: 720

    Rectangle {
        anchors.fill: parent
        color: "#1e1e1e"

        Text {
            anchors.centerIn: parent
            text: "Dashboard"
            color: "white"
            font.pixelSize: 24
        }

        // TODO: Add dashboard components (speed, gear, fuel gauge, etc.)
    }
}
