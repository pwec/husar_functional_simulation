#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position(double a=0, double x=0, double y=0) : m_angle(a), m_x(x), m_y(y) {}
        virtual ~Position();

        void SetPosition(double a, double x, double y){m_angle = a, m_x=0, m_y=0;}

        double GetAngle() { return m_angle; }
        void SetAngle(double val) { m_angle = val; }

        double GetX() { return m_x; }
        void SetX(double val) { m_x = val; }

        double GetY() { return m_y; }
        void SetY(double val) { m_y = val; }
    protected:
    private:
        double m_angle;
        double m_x;
        double m_y;
};

#endif // POSITION_H
