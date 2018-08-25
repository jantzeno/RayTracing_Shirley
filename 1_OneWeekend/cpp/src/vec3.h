#ifndef Vec3_H
#define Vec3_H

#include <cmath>
#include <iostream>

class Vec3
{

public:

  float vector[3];

  Vec3() {}
  Vec3(float e0, float e1, float e2)
    : vector{e0, e1, e2} {}

  inline float x() const { return vector[0]; }
  inline float y() const { return vector[1]; }
  inline float z() const { return vector[2]; }
  inline float r() const { return vector[0]; }
  inline float g() const { return vector[1]; }
  inline float b() const { return vector[2]; }

  inline Vec3 const & operator+() const { return *this; }
  inline Vec3 operator-() const {
    return Vec3(-vector[0],
                -vector[1],
                -vector[2]);
  }
  inline float operator[](int i) const { return vector[i]; }
  inline float& operator[](int i) { return vector[i]; }

  inline Vec3& operator+=(Vec3 const &v2);
  inline Vec3& operator-=(Vec3 const &v2);
  inline Vec3& operator*=(Vec3 const &v2);
  inline Vec3& operator/=(Vec3 const &v2);
  inline Vec3& operator*=(float const t);
  inline Vec3& operator/=(float const t);

  inline float length() const {
    return sqrt( vector[0]*vector[0]
               + vector[1]*vector[1]
               + vector[2]*vector[2] );
  };
  inline float squaredLength() const {
    return vector[0]*vector[0]
         + vector[1]*vector[1]
         + vector[2]*vector[2];
  };
  inline void makeUnitVector();

};

inline void Vec3::makeUnitVector() {
  float k = 1.0 / sqrt( vector[0]*vector[0]
                      + vector[1]*vector[1]
                      + vector[2]*vector[2] );
  vector[0] *= k;
  vector[1] *= k;
  vector[2] *= k;
}

inline std::istream& operator>>(std::istream &is, Vec3 &t) {
  is >> t.vector[0] >> t.vector[1] >> t.vector[2];
  return is;
}

inline std::ostream& operator<<(std::ostream &os, Vec3 const &t) {
  os << t.vector[0] << " " << t.vector[1] << " " << t.vector[2];
  return os;
}

inline Vec3 operator+(Vec3 const &v1, Vec3 const &v2) {
  return Vec3(v1.vector[0] + v2.vector[0],
              v1.vector[1] + v2.vector[1],
              v1.vector[2] + v2.vector[2]);
}

inline Vec3 operator-(Vec3 const &v1, Vec3 const &v2) {
  return Vec3(v1.vector[0] - v2.vector[0],
              v1.vector[1] - v2.vector[1],
              v1.vector[2] - v2.vector[2]);
}

inline Vec3 operator*(Vec3 const &v1, Vec3 const &v2) {
  return Vec3(v1.vector[0] * v2.vector[0],
              v1.vector[1] * v2.vector[1],
              v1.vector[2] * v2.vector[2]);
}

inline Vec3 operator/(Vec3 const &v1, Vec3 const &v2) {
  return Vec3(v1.vector[0] / v2.vector[0],
              v1.vector[1] / v2.vector[1],
              v1.vector[2] / v2.vector[2]);
}

inline Vec3 operator*(float t, Vec3 const &v) {
  return Vec3(t*v.vector[0],
              t*v.vector[1],
              t*v.vector[2]);
}

// Duplicate??
inline Vec3 operator*(Vec3 const &v, float t) {
  return Vec3(t*v.vector[0],
              t*v.vector[1],
              t*v.vector[2]);
}

inline Vec3 operator/(Vec3 v, float t) {
  return Vec3(v.vector[0]/t,
              v.vector[1]/t,
              v.vector[2]/t);
}

inline float dot(Vec3 const &v1, Vec3 const &v2) {
  return v1.vector[0]*v2.vector[0]
       + v1.vector[1]*v2.vector[1]
       + v1.vector[2]*v2.vector[2];
}

inline Vec3 cross(Vec3 const &v1, Vec3 const &v2) {
  return Vec3( (v1.vector[1]*v2.vector[2] - v1.vector[2]*v2.vector[1]),
             (-(v1.vector[0]*v2.vector[2] - v1.vector[2]*v2.vector[0])),
               (v1.vector[0]*v2.vector[1] - v1.vector[1]*v2.vector[0]) );
}

inline Vec3& Vec3::operator+=(Vec3 const &v) {
  vector[0] += v.vector[0];
  vector[1] += v.vector[1];
  vector[2] += v.vector[2];
  return *this;
}

inline Vec3& Vec3::operator-=(Vec3 const &v) {
  vector[0] -= v.vector[0];
  vector[1] -= v.vector[1];
  vector[2] -= v.vector[2];
  return *this;
}

inline Vec3& Vec3::operator*=(Vec3 const &v) {
  vector[0] *= v.vector[0];
  vector[1] *= v.vector[1];
  vector[2] *= v.vector[2];
  return *this;
}

inline Vec3& Vec3::operator/=(Vec3 const &v) {
  vector[0] /= v.vector[0];
  vector[1] /= v.vector[1];
  vector[2] /= v.vector[2];
  return *this;
}

inline Vec3& Vec3::operator*=(float const t) {
  vector[0] *= t;
  vector[1] *= t;
  vector[2] *= t;
  return *this;
}

inline Vec3& Vec3::operator/=(float const t) {
  float k = 1.0/t;
  vector[0] *= k;
  vector[1] *= k;
  vector[2] *= k;
  return *this;
}

inline Vec3 unitVector(Vec3 v) {
  return v / v.length();
}

#endif
