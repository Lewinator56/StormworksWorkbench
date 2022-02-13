/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick
import QtQuick.Controls.Fusion as Fus
import QtQuick.Controls.impl
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl
import QtQuick.Templates as T
import QtQuick.Layouts


T.TabButton {
    id: control

    implicitWidth: control.width
    implicitHeight: 30

    padding: 6
    spacing: 6

    icon.width: 24
    icon.height: 24
    icon.color: checked ? Qt.lighter(Material.primary, 1.5) : Material.background
    Material.elevation: 6


    contentItem: RowLayout {

        IconLabel {
            spacing: control.spacing
            mirrored: control.mirrored
            display: control.display

            icon: control.icon
            text: control.text
            font: control.font
            color: control.checked ? Material.accent : control.palette.brightText

        }
        Fus.Button {
            id: closeButton
            Text {
                text: "x"
                font: control.font

                color: "#ffffff"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideMiddle
                anchors.fill: parent




            }

            onClicked: {
                control.closeTab
            }

            visible: control.checked || control.hovered ? true : false
            width: 20
            height: 20
            implicitWidth: 20
            implicitHeight: 20
            anchors.right: parent.right
            background: Rectangle {
                color: control.checked ? closeButton.hovered ? Qt.lighter("#d32f2f", 1.1) : "#d32f2f" : closeButton.hovered ? "#222222" : "#00000000"
                radius: width*0.5
                layer.effect: ElevationEffect {
                    elevation: control.Material.elevation
                }

            }

        }

    }


    background: Rectangle {
        implicitHeight: 40
        color: Color.blend(control.checked ? Material.primary : control.hovered ? Qt.lighter(Material.background, 5) : Material.background,
                                             control.palette.mid, control.down ? 0.5 : 0.0)
    }

}
