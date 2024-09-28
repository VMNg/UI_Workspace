import QtQuick 2.15
import QtQuick.Controls 2.15
import MDA.Models 1.0
Item{
    property int width_slider: 0
    property int height_slider: 0

    width: width_slider
    height: height_slider

    Slider{
        id: mySlider

        width: width_slider * 0.83
        from: 0
        value: FunctionModel.getPositionForSlider()
        to: FunctionModel.getDurationForSlider()
        stepSize: 1
        background: Rectangle
        {
            x: mySlider.leftPadding
            y: mySlider.topPadding + mySlider.availableHeight / 2 - height / 2
            width: mySlider.availableWidth
            height: 10
            radius: height / 2
            color: "#130f40"

            Rectangle
            {
                width: mySlider.visualPosition == 0 ? 0 : mySlider.handle.x  + mySlider.handle.width / 2
                height: 10
                color: "#7ed6df"
                radius: height / 2
            }
        }
        handle: Rectangle
        {
            x: mySlider.leftPadding + mySlider.visualPosition * (mySlider.availableWidth - width)
            y: mySlider.topPadding + mySlider.availableHeight / 2 - height/ 2
            implicitHeight: 15
            implicitWidth: 15
            radius: implicitWidth / 2
            color: mySlider.pressed ? "#dff9fb" : "#222f3e"
            border.color: "#1dd1a1"
            border.width: 2
        }
    }
    Text {
        id: position_current

        text: FunctionModel.currentPosition;
        anchors{
            right: mySlider.left
            rightMargin: 7
        }
    }
    Text {
        id: position_end

        text: FunctionModel.duration_Media
        anchors{
            left: mySlider.right
            leftMargin: 7
        }
    }

    Connections {
        target: FunctionModel
        function onUpdateSlider() {
            mySlider.value = FunctionModel.getPositionForSlider();
        }
    }

    Connections {
        target: FunctionModel
        function onUpdateDuration() {
            mySlider.to = FunctionModel.getDurationForSlider();
        }
    }

    Connections {
        target: mySlider
        function onMoved(){
            FunctionModel.setPosition(mySlider.value);
        }
    }

}
