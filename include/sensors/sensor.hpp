#pragma once

namespace eekhdv
{

/*
 *
**/
class sensor
{
public:
  virtual ~sensor();

  /// @brief 
  /// @return
  virtual void measure();

private:
};

} // namespace eekhdv
