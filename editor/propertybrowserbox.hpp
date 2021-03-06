/*  Copyright (c) 2013, Abdullah A. Hassan <voodooattack@hotmail.com>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 *  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PROPERTYBROWSERBOX_H
#define PROPERTYBROWSERBOX_H

#include <QWidget>

class QLineEdit;
class QToolButton;

namespace ADWIF
{
  class PropertyBrowseBox: public QWidget
  {
    Q_OBJECT
  public:
    explicit PropertyBrowseBox(QWidget * parent = 0, Qt::WindowFlags f = 0);
    QString text() const;
    void setText(const QString & text);
    bool editable() const;
    void setEditable(bool value);
    QLineEdit * lineEdit() const { return myLineEdit; }
    QToolButton * toolButton() const { return myButton; }
  signals:
    void textChanged(const QString & text);
    void buttonClicked();
  protected:
    void focusInEvent(QFocusEvent * e);
    void focusOutEvent(QFocusEvent * e);
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent * e);
  private:
    QLineEdit * myLineEdit;
    QToolButton * myButton;
  };
}

#endif // PROPERTYBROWSERBOX_H
