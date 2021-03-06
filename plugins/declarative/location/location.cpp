/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativepositionsource_p.h"
#include "qdeclarativeposition_p.h"

#include "qdeclarativegeoboundingbox_p.h"
#include "qdeclarativegeoaddress_p.h"
#include "qdeclarativegeoplace_p.h"
#include "qdeclarativecoordinate_p.h"

#include "qdeclarativegeoserviceprovider_p.h"

#include <QtDeclarative/qdeclarativeextensionplugin.h>
#include <QtDeclarative/qdeclarative.h>

QT_BEGIN_NAMESPACE
QTMS_USE_NAMESPACE

class QLocationDeclarativeModule: public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    virtual void registerTypes(const char* uri) {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QtMobilitySubset.location"));
        // Elements available since Qt mobility 1.1:
        qmlRegisterType<QDeclarativePosition>(uri, 1, 1, "Position");
        qmlRegisterType<QDeclarativePositionSource>(uri, 1, 1, "PositionSource");
        qmlRegisterType<QDeclarativeCoordinate>(uri, 1, 1, "Coordinate");
        qmlRegisterType<QDeclarativeGeoBoundingBox>(uri, 1, 1, "BoundingBox");
        qmlRegisterType<QDeclarativeGeoPlace>(uri, 1, 1, "Place");
        qmlRegisterType<QDeclarativeGeoAddress>(uri, 1, 1, "Address");

        qmlRegisterType<QDeclarativeGeoServiceProvider>(uri, 1, 2, "Plugin");
        qmlRegisterType<QDeclarativeGeoServiceProviderParameter>(uri, 1, 2, "PluginParameter");
    }
};

QT_END_NAMESPACE
#include "location.moc"

Q_EXPORT_PLUGIN2(declarative_location, QT_PREPEND_NAMESPACE(QLocationDeclarativeModule));



