module FetchResult = {
  type t;

  [@bs.module "@react-native-community/push-notification-ios"]
  [@bs.scope ("default", "FetchResult")]
  external newData: t = "NewData";

  [@bs.module "@react-native-community/push-notification-ios"]
  [@bs.scope ("default", "FetchResult")]
  external noData: t = "NoData";

  [@bs.module "@react-native-community/push-notification-ios"]
  [@bs.scope ("default", "FetchResult")]
  external resultFailed: t = "ResultFailed";
};

module Notification = {
  type t;

  [@bs.send] [@bs.return nullable]
  external getAlert: t => option(Js.Json.t) = "getAlert";

  [@bs.send] external getTitle: t => string = "getTitle";

  [@bs.send] [@bs.return nullable]
  external getMessage: t => option(Js.Json.t) = "getMessage";

  [@bs.send] [@bs.return nullable]
  external getSound: t => option(string) = "getSound";

  [@bs.send] [@bs.return nullable]
  external getCategory: t => option(string) = "getCategory";

  // Actually type ContentAvailable = 1 | null | void ...
  [@bs.send] external getContentAvailable: t => bool = "getContentAvailable";

  [@bs.send] [@bs.return nullable]
  external getBadgeCount: t => option(int) = "getBadgeCount";

  [@bs.send] [@bs.return nullable]
  external getData: t => option(Js.Json.t) = "getData";

  [@bs.send] [@bs.return nullable]
  external getThreadID: t => option(string) = "getThreadID";

  [@bs.send] external finish: (t, FetchResult.t) => unit = "finish";
};

type localNotification;

[@bs.obj]
external localNotification:
  (
    ~alertBody: string=?,
    ~alertTitle: string=?,
    ~alertAction: string=?,
    ~soundName: string=?,
    ~isSilent: bool=?,
    ~category: string=?,
    ~userInfo: Js.Json.t=?,
    ~applicationIconBadgeNumber: int=?,
    ~fireDate: Js.Date.t=?,
    ~repeatInterval: [ | `minute | `hour | `day | `week | `month | `year]=?,
    unit
  ) =>
  localNotification;

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external presentLocalNotification: localNotification => unit =
  "presentLocalNotification";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external scheduleLocalNotification: localNotification => unit =
  "scheduleLocalNotification";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external cancelAllLocalNotifications: unit => unit =
  "cancelAllLocalNotifications";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external removeAllDeliveredNotifications: unit => unit =
  "removeAllDeliveredNotifications";

type deliveredNotification = {
  identifier: string,
  date: option(string),
  title: option(string),
  body: option(string),
  category: option(string),
  [@bs.as "thread-id"]
  threadId: option(string),
  userInfo: option(Js.Json.t),
};

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getDeliveredNotifications:
  (array(deliveredNotification) => unit) => unit =
  "getDeliveredNotifications";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external removeDeliveredNotifications: (~identifiers: array(string)) => unit =
  "removeDeliveredNotifications";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external setApplicationIconBadgeNumber: int => unit =
  "setApplicationIconBadgeNumber";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getApplicationIconBadgeNumber: (int => unit) => unit =
  "getApplicationIconBadgeNumber";

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external cancelLocalNotifications: unit => unit = "cancelLocalNotifications";

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external cancelLocalNotificationsWithUserInfo: Js.Json.t => unit =
  "cancelLocalNotifications";

type formattedLocalNotification = {
  fireDate: option(string),
  alertAction: option(string),
  alertTitle: option(string),
  alertBody: option(string),
  applicationIconBadgeNumber: option(int),
  category: option(string),
  repeatInterval: option(string),
  soundName: option(string),
  userInfo: option(Js.Json.t),
};

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getScheduledLocalNotifications:
  (array(formattedLocalNotification) => unit) => unit =
  "getScheduledLocalNotifications";

type registrationError('a) = {
  message: string,
  code: int,
  details: Js.t('a),
};

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external addEventListener:
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit =
  "addEventListener";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external removeEventListener:
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit =
  "removeEventListener";

type permissions = {
  alert: bool,
  badge: bool,
  sound: bool,
  lockScreen: bool,
  notificationCenter: bool,
};

type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions;

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external requestPermissions: unit => Js.Promise.t(permissions) =
  "requestPermissions";

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external requestPermissionsWithOptions:
  requestPermissionsOptions => Js.Promise.t(permissions) =
  "requestPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external abandonPermissions: unit => unit = "abandonPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external checkPermissions: (unit => permissions) => unit = "checkPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getInitialNotification:
  unit => Js.Promise.t(Js.Nullable.t(Notification.t)) =
  "getInitialNotification";
