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

/**
 * Alert Object that can be included in the aps `alert` object
 */
type notificationAlert = {
  title: option(string),
  subtitle: option(string),
  body: option(string),
};

type notificationActionOptions = {
  foreground: option(bool),
  destructive: option(bool),
  authenticationRequired: option(bool),
};

type notificationActionTextInput = {
  /**
   * Text to be shown on button when user finishes text input.
   * Default is "Send" or its equivalent word in user's language setting.
   */
  buttonTitle: option(string),
  /**
   * Placeholder for text input for text input action.
   */
  placeholder: option(string),
};

/**
 * Notification Action that can be added to specific categories
 */
type notificationAction = {
  /**
   * Id of Action.
   * This value will be returned as actionIdentifier when notification is received.
   */
  id: string,
  /**
   * Text to be shown on notification action button.
   */
  title: string,
  /**
   * Option for notification action.
   */
  options: option(notificationActionOptions),
  /**
   * Option for textInput action.
   * If textInput prop exists, then user action will automatically become a text input action.
   * The text user inputs will be in the userText field of the received notification.
   */
  textInput: option(notificationActionTextInput),
};

module Notification = {
  type t;

  [@bs.send] [@bs.return nullable]
  // string | notificationAlert
  external getAlert: t => option(Js.Json.t) = "getAlert";

  [@bs.send] external getTitle: t => string = "getTitle";

  [@bs.send] [@bs.return nullable]
  // string | notificationAlert
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

  /**
   * Get's the action id of the notification action user has taken.
   */
  [@bs.send] [@bs.return nullable]
  external getActionIdentifier: t => option(string) = "getActionIdentifier";

  /**
   * Gets the text user has inputed if user has taken the text action response.
   */
  [@bs.send] [@bs.return nullable]
  external getUserText: t => option(string) = "getUserText";

  [@bs.send] [@bs.return nullable]
  external getThreadID: t => option(string) = "getThreadID";

  [@bs.send] external finish: (t, FetchResult.t) => unit = "finish";
};

type notificationRequest = {
  /**
   * identifier of the notification.
   * Required in order to retrieve specific notification.
   */
  id: string,
  /**
   * A short description of the reason for the alert.
   */
  title: option(string),
  /**
   * A secondary description of the reason for the alert.
   */
  subtitle: option(string),
  /**
   * The message displayed in the notification alert.
   */
  body: option(string),
  /**
   * The number to display as the app's icon badge.
   */
  badge: option(int),
  /**
   * The sound to play when the notification is delivered.
   */
  sound: option(string),
  /**
   * The category of this notification. Required for actionable notifications.
   */
  category: option(string),
  /**
   * The thread identifier of this notification.
   */
  threadId: option(string),
  /**
   * The date which notification triggers.
   */
  fireDate: option(Js.Date.t),
  /**
   * Sets notification to repeat daily.
   * Must be used with fireDate.
   */
  repeats: option(bool),
  /**
   * Sets notification to be silent
   */
  isSilent: option(bool),
  /**
   * Optional data to be added to the notification
   */
  userInfo: option(Js.Json.t),
};

[@bs.obj]
external notificationRequest:
  (
    ~id: string,
    ~title: string=?,
    ~subtitle: string=?,
    ~body: string=?,
    ~badge: int=?,
    ~sound: string=?,
    ~category: string=?,
    ~threadId: string=?,
    ~fireDate: Js.Date.t=?,
    ~repeats: bool=?,
    ~isSilent: bool=?,
    ~userInfo: Js.Json.t=?,
    unit
  ) =>
  notificationRequest;

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external addNotificationRequest: notificationRequest => unit =
  "addNotificationRequest";

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

[@deprecated "Please use addNotificationRequest instead"]
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external presentLocalNotification: localNotification => unit =
  "presentLocalNotification";

[@deprecated "Please use addNotificationRequest instead"]
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external scheduleLocalNotification: localNotification => unit =
  "scheduleLocalNotification";

[@deprecated "Please use removeAllPendingNotificationRequests instead"]
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external cancelAllLocalNotifications: unit => unit =
  "cancelAllLocalNotifications";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external removeAllPendingNotificationRequests: unit => unit =
  "removeAllPendingNotificationRequests";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external removeAllDeliveredNotifications: unit => unit =
  "removeAllDeliveredNotifications";

type deliveredNotification = {
  identifier: string,
  date: option(string),
  title: option(string),
  subtitle: option(string),
  body: option(string),
  category: option(string),
  actionIdentifier: option(string),
  [@bs.as "thread-id"]
  threadId: option(string),
  userText: option(string),
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

[@deprecated "Please use getPendingNotificationRequests instead"]
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getScheduledLocalNotifications:
  (array(formattedLocalNotification) => unit) => unit =
  "getScheduledLocalNotifications";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getPendingNotificationRequests:
  (array(notificationRequest) => unit) => unit =
  "getPendingNotificationRequests";

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

type requestedPermissions = {
  alert: bool,
  badge: bool,
  sound: bool,
};

type checkedPermissions = {
  alert: bool,
  badge: bool,
  sound: bool,
  lockScreen: bool,
  notificationCenter: bool,
  // https://developer.apple.com/documentation/usernotifications/unauthorizationstatus
  authorizationStatus: int,
};

type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions;

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external requestPermissions: unit => Js.Promise.t(requestedPermissions) =
  "requestPermissions";

// multiple externals
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external requestPermissionsWithOptions:
  requestPermissionsOptions => Js.Promise.t(requestedPermissions) =
  "requestPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external abandonPermissions: unit => unit = "abandonPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external checkPermissions: (unit => checkedPermissions) => unit =
  "checkPermissions";

[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external getInitialNotification:
  unit => Js.Promise.t(Js.Nullable.t(Notification.t)) =
  "getInitialNotification";

/**
 * Notification Category that can include specific actions
 */
type notificationCategory = {
  id: string,
  actions: array(notificationAction),
};
[@bs.module "@react-native-community/push-notification-ios"]
[@bs.scope "default"]
external setNotificationCategories:
  array(notificationCategory) => Js.Promise.t(unit) =
  "setNotificationCategories";
