import QtQuick
import QtQuick.Layouts

Window {
    visible: true
    color: "#1E3A5F"

    Rectangle{
        anchors{
            top: parent.top
            topMargin: 10
            left: parent.left
            leftMargin: 50
            right: parent.right
            rightMargin: 50
            bottom: parent.bottom
            bottomMargin: 50
        }
        color: "#1E3A5F"

        GridLayout{
            id: grid
            anchors.fill: parent
            columns: 5
            rows: 3
            columnSpacing: 5
            rowSpacing: 5

            Rectangle{
                id: speed
                color: "grey"
                opacity: 0.1
                Layout.preferredWidth: 50
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.rowSpan: 2
            }

            Rectangle{
                id: gear
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 25
                Layout.preferredHeight: 50
                Layout.rowSpan: 2
            }
            Rectangle{
                id: doorLock
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumWidth: grid.width - gear.width - speed.width
                Layout.preferredHeight: 100
                Layout.columnSpan: 3
            }
            Rectangle{
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
            }
            Rectangle{
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
                Layout.columnSpan: 2
            }
            Rectangle{
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 3
            }
            Rectangle{
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
            }
            Rectangle{
                color: "grey"
                opacity: 0.1
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
            }
        }
    }
}
