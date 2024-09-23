import QtQuick 2.15
import QtQuick.Controls 2.15
import MDA.Models 1.0
import "./Climate"
import "./Dashboard"
import "./Media"

ApplicationWindow {
    width: 1080
    height: 720
    visible: true
    title: qsTr("PBL Application")

    header: Rectangle {
        width: parent.width
        height: 50
        color: "#2c3e50"  // Dark blue background

        Row {
            id: tabBar
            anchors.fill: parent

            property int currentIndex: 0

            CustomTabButton {
                text: qsTr("Dashboard")
                isCurrentItem: tabBar.currentIndex === 0
                onClicked: tabBar.currentIndex = 0
            }
            CustomTabButton {
                text: qsTr("Climate")
                isCurrentItem: tabBar.currentIndex === 1
                onClicked: tabBar.currentIndex = 1
            }
            CustomTabButton {
                text: qsTr("Audio/Video")
                isCurrentItem: tabBar.currentIndex === 2
                onClicked: tabBar.currentIndex = 2
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Dashboard {}
        Climate {}
        Media {}
    }

    Connections {
        target: tabBar
        function onCurrentIndexChanged() {
            swipeView.currentIndex = tabBar.currentIndex
        }
    }
}
