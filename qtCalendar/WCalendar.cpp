#include "WCalendar.h"
#include <exception>
#include <stdexcept>

WCalendar::WCalendar()
{

}

WCalendarNamespace::WDatePeriod::WDatePeriod(const QDate &_start, const QDate &_end):
    t_start(_start), t_end(_end)
{
    if (t_start != QDate() && t_end != QDate() && t_start > t_end) throw std::exception();
}

QDate WCalendarNamespace::WDatePeriod::start() const
{
    return t_start;
}

QDate WCalendarNamespace::WDatePeriod::end() const
{
    return t_end;
}

bool WCalendarNamespace::WDatePeriod::in(const QDate &op) const
{
    return (t_start <= op && op <= t_end);
}

WCalendarNamespace::WAbstractAnniversary::WAbstractAnniversary()
{

}

WCalendarNamespace::WDatePeriod WCalendarNamespace::WAbstractAnniversary::getDefinedRange() const
{
    return foundation;
}

void WCalendarNamespace::WAbstractAnniversary::setDefinedRange(const WCalendarNamespace::WDatePeriod &foun)
{
    foundation = foun;
}

WCalendarNamespace::WGregoryAnniversary::WGregoryAnniversary(int startyear, int endyear, int month, int mday)
{
    t_month = month;
    t_mday = mday;
    setDefinedRange(WDatePeriod(QDate(startyear,1,1),QDate(endyear,12,31)));
}

QDate WCalendarNamespace::WGregoryAnniversary::indexed(int year) const
{
    return QDate(year,t_month,t_mday);
}

QList<QDate> WCalendarNamespace::WGregoryAnniversary::ranged(const WCalendarNamespace::WDatePeriod &range) const
{
    QList<QDate> result;
    int year = range.start().year();
    if (QDate(year,t_month,t_mday) < range.start()) year++;
    for (;temp <= range.end(); temp.addYears(1));
    return result;
}

QDate WCalendarNamespace::WKoreanHolidays::Seolnal(int year)
{
    if (year == 2006) return QDate(2006,1,29);
    if (year == 2007) return QDate(2007,2,18);
    if (year == 2008) return QDate(2008,2, 7);
    if (year == 2009) return QDate(2009,1,26);
    if (year == 2010) return QDate(2010,2,14);
    if (year == 2011) return QDate(2011,2, 3);
    if (year == 2012) return QDate(2012,1,23);
    if (year == 2013) return QDate(2013,2,10);
    if (year == 2014) return QDate(2014,1,31);
    if (year == 2015) return QDate(2015,2,19);
    if (year == 2016) return QDate(2016,2, 8);
    if (year == 2017) return QDate(2017,1,28);
    if (year == 2018) return QDate(2018,2,16);
    if (year == 2019) return QDate(2019,2, 5);
    if (year == 2020) return QDate(2020,1,25);
    if (year == 2021) return QDate(2021,2,12);
    if (year == 2022) return QDate(2022,2, 1);
    if (year == 2023) return QDate(2023,1,22);
    if (year == 2024) return QDate(2024,2,10);
    if (year == 2025) return QDate(2025,1,29);
    if (year == 2026) return QDate(2026,2,17);
    if (year == 2027) return QDate(2027,2, 7);
}
