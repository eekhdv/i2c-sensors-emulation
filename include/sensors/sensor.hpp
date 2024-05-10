#pragma once

namespace eekhdv
{

class sensor
{
public:
  virtual ~sensor();

  virtual void measure();

private:
};

} // namespace eekhdv
