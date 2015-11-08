#include "NudibranchApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<NudibranchApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

NudibranchApp::NudibranchApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  NudibranchApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  NudibranchApp::associateSyntax(_syntax, _action_factory);
}

NudibranchApp::~NudibranchApp()
{
}

// External entry point for dynamic application loading
extern "C" void NudibranchApp__registerApps() { NudibranchApp::registerApps(); }
void
NudibranchApp::registerApps()
{
  registerApp(NudibranchApp);
}

// External entry point for dynamic object registration
extern "C" void NudibranchApp__registerObjects(Factory & factory) { NudibranchApp::registerObjects(factory); }
void
NudibranchApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void NudibranchApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { NudibranchApp::associateSyntax(syntax, action_factory); }
void
NudibranchApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
