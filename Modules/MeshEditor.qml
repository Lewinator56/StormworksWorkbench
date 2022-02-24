import QtQuick 2.0
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick3D
import meshdata.swmesh
import meshdata.meshqtmodel
import QtQuick3D.Helpers


Item {
    Button {
        leftPadding: 500
        onClicked: setMesh();
        text: "test"
    }

    View3D {
           id: view
           anchors.fill: parent



           environment: SceneEnvironment {
               clearColor: "skyblue"
               backgroundMode: SceneEnvironment.Color
           }

           PerspectiveCamera {
                       id: camera
                       position: Qt.vector3d(0, 0, 600)
                       clipFar: 100000
                   }

           DirectionalLight {
               eulerRotation.x: -30
               eulerRotation.y: -70
           }

           Model {
               id: customModel
               scale: Qt.vector3d(100, 100, 100)
               geometry: MeshQtModel {
                   id: geom
               }
               materials: [
                   DefaultMaterial {
                       cullMode: DefaultMaterial.NoCulling
                   }
               ]
           }

       }

    WasdController {
        controlledObject: camera
    }

    function setMesh() {
        geom.addSwMesh("D:/Program Files/Steam/steamapps/common/Stormworks/rom/meshes/TankPartsPack/stabilized_sight_1.mesh")

    }
}
