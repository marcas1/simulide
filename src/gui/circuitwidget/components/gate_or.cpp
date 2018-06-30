/***************************************************************************
 *   Copyright (C) 2012 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
#include "gate_or.h"
#include "itemlibrary.h"


Component* OrGate::construct( QObject* parent, QString type, QString id )
{
        return new OrGate( parent, type, id );
}

LibraryItem* OrGate::libraryItem()
{
    return new LibraryItem(
        tr( "Or Gate" ),
        tr( "Logic" ),
        "orgate.png",
        "Or Gate",
        OrGate::construct );
}

OrGate::OrGate( QObject* parent, QString type, QString id )
        : Gate( parent, type, id, 2 )
{
}
OrGate::~OrGate(){}

bool OrGate::calcOutput( int inputs )
{
    if( inputs > 0 )  return true;

    return false;
}

QPainterPath OrGate::shape() const
{
    QPainterPath path;
    
    QVector<QPointF> points;
    
    points << QPointF(-20,-18 )
           << QPointF(-16,-8  )
           << QPointF(-16, 8  )
           << QPointF(-20, 18 )
           << QPointF(  0, 16 )
           << QPointF( 16, 8  )
           << QPointF( 16,-8  )
           << QPointF(  0,-16 );
        
    path.addPolygon( QPolygonF(points) );
    path.closeSubpath();
    return path;
}

void OrGate::paint( QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    int y_orig = this->boundingRect().y();
    int height = this->boundingRect().height();

    // Paint white background of gate
    Component::paint( p, option, widget );
    QPen pen = p->pen();
    
    p->setPen( Qt::NoPen );

    QPainterPath path;
    
    path.moveTo( -16, 0 );
    path.arcTo( -55, y_orig, 71, height, -90, 180 );
    
    path.moveTo( -16, 0 );
    path.arcTo( -24, y_orig, 9, height, -90, 180 );

    p->drawPath(path);

    // Draw curves
    
    pen.setWidth(2);
    p->setPen(pen);
    
    p->setBrush( Qt::NoBrush );

    // Output side arc
    p->drawArc( -48, y_orig, 64, height, -1520/*-16*95*/, 3040/*16*190*/ );

    // Input side arc
    p->drawArc( -24, y_orig, 9, height, -1440/*-16*90*/, 2880/*16*180*/ );
}

#include "moc_gate_or.cpp"


