// Манхэттенское расстояние (4 направления)
double calculate(const Point& current, const Point& goal) {
    return std::abs(current.x - goal.x) + std::abs(current.y - goal.y);
}

// Расстояние Чебышева (8 направлений с диагоналями)
double calculate(const Point& current, const Point& goal) {
    return std::max(std::abs(current.x - goal.x), std::abs(current.y - goal.y));
}

// Евклидово расстояние (любое направление)
double calculate(const Point& current, const Point& goal) {
    int dx = current.x - goal.x;
    int dy = current.y - goal.y;
    return std::sqrt(dx * dx + dy * dy);
}
