#ifndef NUDIBRANCHAPP_H
#define NUDIBRANCHAPP_H

#include "MooseApp.h"

class NudibranchApp;

template<>
InputParameters validParams<NudibranchApp>();

class NudibranchApp : public MooseApp
{
public:
  NudibranchApp(InputParameters parameters);
  virtual ~NudibranchApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* NUDIBRANCHAPP_H */
