import QtQuick 2.15

Item {
    Rectangle{
        id: background
        height: 470
        width: 720
        color: "#1e1e1e"

        Image{
            id: imageSong
            source: "qrc:/iconControlMedia/playingMusic.png"
            width: 256
            height: 256
            anchors.centerIn: background

            NumberAnimation on rotation {
                id: rotateAnim
                from: 0
                to: 360
                duration: 3000
                running: playerControl.running
                loops: Animation.Infinite
            }
        }
    }
}
