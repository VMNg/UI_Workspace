import QtQuick 2.15
import QtQuick.Controls
import MDA.Models 1.0
Item {
    width: 720
    height: 470
    visible: FunctionModel.running ? true : false
    Rectangle{
        id: background
        width: 720
        height: 470
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
                running: FunctionModel.running
                loops: Animation.Infinite
            }
        }
    }
}
