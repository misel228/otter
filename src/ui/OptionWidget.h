/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_OPTIONWIDGET_H
#define OTTER_OPTIONWIDGET_H

#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

namespace Otter
{

class OptionWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OptionWidget(bool simple, const QString &option, const QString &type, const QVariant &value, const QStringList &choices, const QModelIndex &index, QWidget *parent = NULL);

	QVariant getValue() const;
	QModelIndex getIndex() const;

protected slots:
	void selectColor();
	void modified();
	void reset();
	void save();

private:
	QString m_option;
	QModelIndex m_index;
	QPushButton *m_resetButton;
	QPushButton *m_saveButton;
	QPushButton *m_colorButton;
	QComboBox *m_comboBox;
	QFontComboBox *m_fontComboBox;
	QLineEdit *m_lineEdit;
	QSpinBox *m_spinBox;

signals:
	void commitData(QWidget *editor);
};

}

#endif
