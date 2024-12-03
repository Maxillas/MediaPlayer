import QtQuick
import QtQuick.Layouts

Item {
  id: root
  property color txtColor: "#56b4d0"
  Rectangle {
    id: center
    height: parent.height
    width: 15
    anchors.horizontalCenter: parent.horizontalCenter
    color: transparentColor
  }
  Rectangle {
    id: left
    height: parent.height
    width: parent.width / 2.2
    anchors.right: center.left
    color: transparentColor
    ColumnLayout {
      spacing: 5

      Text {
        Layout.alignment: Qt.AlignRight
        text: "filter"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "HightPass"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "time"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "program"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "left: 100"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "delay"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "precession"
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignRight
        text: "switch"
        color: txtColor
      }
    }
  }

  Rectangle {
    id: right
    height: parent.height
    width: parent.width / 2.2
    anchors.left: center.right
    color: transparentColor
    ColumnLayout {
      spacing: 5

      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().filter ? "On" : "Off"
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().hightPass + " Hz"
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().time + " sec"
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().program
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          "right: " + AudioPlayer.settingsManager().right
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().delay + " ms"
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().precession + " ms"
        }
        color: txtColor
      }
      Text {
        Layout.alignment: Qt.AlignLeft
        text: {
          if(!AudioPlayer) {return ""}
          AudioPlayer.settingsManager().switchs
        }
        color: txtColor
      }
    }
  }




}
