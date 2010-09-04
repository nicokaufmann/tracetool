/**********************************************************************
** Copyright (C) 2010 froglogic GmbH.
** All rights reserved.
**********************************************************************/

#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QLineEdit>

class QHBoxLayout;
class QPushButton;
class QStringList;

class UnlabelledLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    UnlabelledLineEdit( QWidget *parent );

    void setPlaceholderText( const QString &placeholderText );

protected:
    virtual void paintEvent( QPaintEvent *e );

private:
    QString m_placeholderText;
};

class SearchWidget : public QWidget
{
    Q_OBJECT
public:
    SearchWidget( QWidget *parent = 0 );

    void setFields( const QStringList &fields );
signals:
    void searchCriteriaChanged( const QString &term,
                                const QStringList &fields );

private slots:
    void termEdited( const QString &term );
    void fieldsChanged();

private:
    void emitSearchCriteria();

    UnlabelledLineEdit *m_lineEdit;
    QList<QPushButton *> m_fieldButtons;
    QHBoxLayout *m_buttonLayout;
};

#endif // !defined(SEARCHWIDGET_H)
