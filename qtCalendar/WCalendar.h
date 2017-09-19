#ifndef WCALENDAR_H
#define WCALENDAR_H

#include <QDate>
#include <QList>

class WCalendar
{
public:
    WCalendar();
};


namespace WCalendarNamespace{
    class WDatePeriod{
    private:
        QDate t_start, t_end;
    public:
        WDatePeriod(const QDate& _start = QDate(), const QDate& _end = QDate());
        QDate start() const;
        QDate end() const;
        bool in(const QDate&) const;
    };

    class WAbstractAnniversary{
    private:
        WDatePeriod foundation;
    protected:
        WAbstractAnniversary();
    public:
        WDatePeriod getDefinedRange() const;
        void setDefinedRange(const WDatePeriod& foun);

        virtual QDate indexed(int year) const = 0;
        virtual QList<QDate> ranged(const WDatePeriod& range) const = 0;
    };

    class WGregoryAnniversary: public WAbstractAnniversary{
    private:
        int t_month, t_mday;
    public:
        WGregoryAnniversary(int startyear, int endyear, int month, int mday);
        virtual QDate indexed(int year) const;
        virtual QList<QDate> ranged(const WDatePeriod& range) const;
    };

    /*
    struct WKoreanJapanese{
        static constexpr QDate start = QDate(1910,10,1); //언제시작?총독부?
        static constexpr QDate end = QDate(1945,9,2);

    };
*/
    struct WKoreanHolidays{
        static QDate Seolnal(int year);
        static QDate Chuseok(int year);
    };
}

#endif // WCALENDAR_H
