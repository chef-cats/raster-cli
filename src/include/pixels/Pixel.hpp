#pragma once

/**
 * Forward declaration of Operation.
 *
 * @see Operation
 */

class Operation;

/**
 * Base class of the pixel hierarchy.
 *
 * This and Operation are implemented using the
 * <a href="https://sourcemaking.com/design_patterns/visitor">visitor design pattern</a>.
 * Operation is the visitor class.
 */

class Pixel {
public:
  virtual ~Pixel() = default;

  virtual void apply(const Operation &operation) = 0;
};
