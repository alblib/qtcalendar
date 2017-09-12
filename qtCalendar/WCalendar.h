#ifndef WCALENDAR_H
#define WCALENDAR_H

#include <QDate>

class WCalendar
{
public:
    WCalendar();
};


namespace WCalendarNamespace{
    struct WDatePeriod{
        QDate start,end;
        WDatePeriod(const QDate& _start = QDate(), const QDate& _end = QDate()):
            start(_start), end(_end)
        {
            if (start == QDate())
        }

    };

    struct WKoreanJapanese{
        static constexpr QDate start = QDate(1910,10,1); //언제시작?총독부?
        static constexpr QDate end = QDate(1945,9,2);

    };

    struct WKoreanHolidays{
        static QDate Seolnal(int year);
        static QDate Chuseok(int year);
    };
}

#endif // WCALENDAR_H
