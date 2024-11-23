import QtQuick 2.15
import QtQuick.Controls 2.15

Slider {
  id: root
  height: 7
  from: 0
  to: 100
  property color textColor: "#5caabe"
  enabled: AudioPlayer.isPlaying
  function setPosition(position) {
    value = (position / AudioPlayer.duration) * 100;
  }

  background: Item {
      implicitWidth: 200
      implicitHeight: 6

      Rectangle { // Общая полоса
          anchors.fill: parent
          color: "#0c4b5d"
          radius: height / 2
      }

      Rectangle { // Полоса прогресса
          width: root.visualPosition * parent.width // Заполняется пропорционально значению
          height: parent.height
          color: "#5caabe" // Цвет заполнения
          radius: height / 2
      }
  }

  handle: Rectangle {
      color: "#5caabe"
  }

  onValueChanged: {
    if(pressed) {
      AudioPlayer.setPositon(value)
    }
  }
  Component.onCompleted: {
    AudioPlayer.positionChanged.connect(root.setPosition)
  }

}

