import QtQuick 2.15
import QtQuick.Controls.Basic

//============================== AIRFLOW FUNCTION ==========================

Item {
    id: item1
    width: 248
    height: 56

    /*Each rectangle is for each function*/
    Rectangle {
        id: rectangle1
        width: parent.width / 4
        height: parent.height
        color: "#ffffff"
        radius: 5
        anchors.left: parent.left
        anchors.top: parent.top

        /*Display an image inside the button, the source of this image is declared in list element*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/ventilation-above.png"
            height: 30
            width: 30
            anchors.horizontalCenter: rectangle1.horizontalCenter
            anchors.verticalCenter: rectangle1.verticalCenter
        }

        /*State of a button, after clicked once, the button will change its state to "stateOn" and vice versa*/
        states: [
            State {
                name: "stateOn"
                PropertyChanges { target: rectangle1; border.color: "green"; border.width: 3; radius: 5; }                        },
            State {
                name: "stateOff"
                PropertyChanges { target: rectangle1; border.width: 0; }
            }
        ]

        /*Mouse area to allow clicking on the button, allowing the button to change state and its current state to be saved into the ini file.
        Furthermore, when a button is clicked and its state changed to "stateOn", other buttons will be changed to "stateOff"
        */
        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            Connections {
                target: mouseArea1
                function onClicked(){
                    if (rectangle1.state === "stateOn") {
                        rectangle1.state = "stateOff"
                        settingsHVAC.setAirFlow(-1)
                    } else {
                        rectangle1.state = "stateOn"
                        rectangle2.state = "stateOff"
                        rectangle3.state = "stateOff"
                        rectangle4.state = "stateOff"
                        settingsHVAC.setAirFlow(0)
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle2
        width: parent.width / 4
        height: parent.height
        color: "#ffffff"
        radius: 5
        anchors.left: rectangle1.right

        /*Display an image inside the button, the source of this image is declared in list element*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/ventilation-below.png"
            height: 30
            width: 30
            anchors.horizontalCenter: rectangle2.horizontalCenter
            anchors.verticalCenter: rectangle2.verticalCenter
        }

        /*State of a button, after clicked once, the button will change its state to "stateOn" and vice versa*/
        states: [
            State {
                name: "stateOn"
                PropertyChanges { target: rectangle2; border.color: "green"; border.width: 3; radius: 5; }                        },
            State {
                name: "stateOff"
                PropertyChanges { target: rectangle2; border.width: 0; }
            }
        ]

        /*Mouse area to allow clicking on the button, allowing the button to change state and its current state to be saved into the ini file.
        Furthermore, when a button is clicked and its state changed to "stateOn", other buttons will be changed to "stateOff"
        */
        MouseArea {
            id: mouseArea2
            anchors.fill: parent
            Connections {
                target: mouseArea2
                function onClicked(){
                    if (rectangle2.state === "stateOn") {
                        rectangle2.state = "stateOff"
                        settingsHVAC.setAirFlow(-1)
                    } else {
                        rectangle1.state = "stateOff"
                        rectangle2.state = "stateOn"
                        rectangle3.state = "stateOff"
                        rectangle4.state = "stateOff"
                        settingsHVAC.setAirFlow(1)
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle3
        width: parent.width / 4
        height: parent.height
        color: "#ffffff"
        radius: 5
        anchors.left: rectangle2.right

        /*Display an image inside the button, the source of this image is declared in list element*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/ventilation-all.png"
            height: 30
            width: 30
            anchors.horizontalCenter: rectangle3.horizontalCenter
            anchors.verticalCenter: rectangle3.verticalCenter
        }

        /*State of a button, after clicked once, the button will change its state to "stateOn" and vice versa*/
        states: [
            State {
                name: "stateOn"
                PropertyChanges { target: rectangle3; border.color: "green"; border.width: 3; radius: 5; }                        },
            State {
                name: "stateOff"
                PropertyChanges { target: rectangle3; border.width: 0; }
            }
        ]

        /*Mouse area to allow clicking on the button, allowing the button to change state and its current state to be saved into the ini file.
        Furthermore, when a button is clicked and its state changed to "stateOn", other buttons will be changed to "stateOff"
        */
        MouseArea {
            id: mouseArea3
            anchors.fill: parent
            Connections {
                target: mouseArea3
                function onClicked(){
                    if (rectangle3.state === "stateOn") {
                        rectangle3.state = "stateOff"
                        settingsHVAC.setAirFlow(-1)
                    } else {
                        rectangle1.state = "stateOff"
                        rectangle2.state = "stateOff"
                        rectangle3.state = "stateOn"
                        rectangle4.state = "stateOff"
                        settingsHVAC.setAirFlow(2)
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle4
        width: parent.width / 4
        height: parent.height
        color: "#ffffff"
        radius: 5
        anchors.left: rectangle3.right

        /*Display an image inside the button, the source of this image is declared in list element*/
        Image {
            source: "qrc:/ui/HVACScreen/IconPic/ventilation-heat.png"
            height: 30
            width: 30
            anchors.horizontalCenter: rectangle4.horizontalCenter
            anchors.verticalCenter: rectangle4.verticalCenter
        }

        /*State of a button, after clicked once, the button will change its state to "stateOn" and vice versa*/
        states: [
            State {
                name: "stateOn"
                PropertyChanges { target: rectangle4; border.color: "green"; border.width: 3; radius: 5; }                        },
            State {
                name: "stateOff"
                PropertyChanges { target: rectangle4; border.width: 0; }
            }
        ]

        /*Mouse area to allow clicking on the button, allowing the button to change state and its current state to be saved into the ini file.
        Furthermore, when a button is clicked and its state changed to "stateOn", other buttons will be changed to "stateOff"
        */
        MouseArea {
            id: mouseArea4
            anchors.fill: parent
            Connections {
                target: mouseArea4
                function onClicked(){
                    if (rectangle4.state === "stateOn") {
                        rectangle4.state = "stateOff"
                        settingsHVAC.setAirFlow(-1)
                    } else {
                        rectangle1.state = "stateOff"
                        rectangle2.state = "stateOff"
                        rectangle3.state = "stateOff"
                        rectangle4.state = "stateOn"
                        settingsHVAC.setAirFlow(3)
                    }
                }
            }
        }
    }

    /*Used to load the data from the ini file, and changed the state of those buttons accordingly*/
    Component.onCompleted:{
        if(datasHVAC.getValue("airflow","airflow")==="-1")
        {
            rectangle1.state = "stateOff"
            rectangle2.state = "stateOff"
            rectangle3.state = "stateOff"
            rectangle4.state = "stateOff"
        }
        else if(datasHVAC.getValue("airflow","airflow")==="0")
        {
            rectangle1.state = "stateOn"
            rectangle2.state = "stateOff"
            rectangle3.state = "stateOff"
            rectangle4.state = "stateOff"
        }
        else if(datasHVAC.getValue("airflow","airflow")==="1")
        {
            rectangle1.state = "stateOff"
            rectangle2.state = "stateOn"
            rectangle3.state = "stateOff"
            rectangle4.state = "stateOff"
        }
        else if(datasHVAC.getValue("airflow","airflow")==="2")
        {
            rectangle1.state = "stateOff"
            rectangle2.state = "stateOff"
            rectangle3.state = "stateOn"
            rectangle4.state = "stateOff"
        }
        else if(datasHVAC.getValue("airflow","airflow")==="3")
        {
            rectangle1.state = "stateOff"
            rectangle2.state = "stateOff"
            rectangle3.state = "stateOff"
            rectangle4.state = "stateOn"
        }
    }
}
