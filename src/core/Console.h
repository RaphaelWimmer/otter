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

#ifndef OTTER_CONSOLE_H
#define OTTER_CONSOLE_H

#include <QtCore/QDateTime>
#include <QtCore/QObject>

namespace Otter
{

enum MessageCategory
{
	OtherMessageCategory = 0,
	NetworkMessageCategory = 1,
	SecurityMessageCategory = 2,
	JavaScriptMessageCategory = 3
};

enum MessageLevel
{
	UnknownMessageLevel = 0,
	LogMessageLevel = 1,
	WarningMessageLevel = 2,
	ErrorMessageLevel = 3
};

struct ConsoleMessage
{
	QDateTime time;
	QString note;
	QString source;
	MessageCategory category;
	MessageLevel level;
	qint64 window;
	int line;
};

class Console : public QObject
{
	Q_OBJECT

public:
	~Console();

	static void createInstance(QObject *parent = NULL);
	static void addMessage(const QString &note, MessageCategory category, MessageLevel level, const QString &source = QString(), int line = -1, qint64 window = -1);
	static Console* getInstance();
	static QList<ConsoleMessage*> getMessages();

protected:
	explicit Console(QObject *parent = NULL);

private:
	static Console *m_instance;
	static QList<ConsoleMessage*> m_messages;

signals:
	void messageAdded(ConsoleMessage *message);
};

}

#endif
