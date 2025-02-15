// Copyright (c) 2022 Manuel Schneider

#pragma once
#include "albert/extensionregistry.h"
#include "albert/extensions/indexqueryhandler.h"
#include "nativepluginprovider.h"
#include "pluginregistry.h"
#include "queryengine.h"
#include "rpcserver.h"
#include "settings/settingswindow.h"
#include "terminalprovider.h"
#include "trayicon.h"
#include "hotkey.h"
#include <QPointer>

class App : public albert::IndexQueryHandler
{
public:
    explicit App(const QStringList &additional_plugin_paths);
    ~App() override;

    void initialize();

    // IndexQueryHandler
    QString id() const override;
    QString name() const override;
    QString description() const override;
    std::vector<albert::IndexItem> indexItems() const override;

    albert::ExtensionRegistry extension_registry;
    PluginRegistry plugin_registry;
    QueryEngine query_engine;
    NativePluginProvider plugin_provider;
    TerminalProvider terminal_provider;
    RPCServer rpc_server;
    TrayIcon tray_icon;
    QPointer<SettingsWindow> settings_window;
    Hotkey hotkey;
};
