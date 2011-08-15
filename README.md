# Kendra API Builder

* Current version: [saracen.kendra.org](http://saracen.kendra.org/)
* SCM: https://github.com/kendrainitiative/kendra_api_builder

### Contributors:

* Daniel Klokie Grossfeld, [Kendra Foundation](http://kendra.org.uk/)

### Notation and Conventions

The key words "MUST", "MUST NOT", "REQUIRED", "SHALL", "SHALL NOT", "SHOULD", "SHOULD NOT", "RECOMMENDED", "MAY", and "OPTIONAL" in this document are to be interpreted as described in RFC2119 [RFC2119].

### Overview

The Kendra Saracen Metadata API is an asynchronous interface for formatting, storing and retrieving user profile and multimedia content metadata and recommendations. The Saracen user and content metadata profile specification consists of both JavaScript APIs and REST/RPC protocols for server-to-server interactions.

Kendra will create a new website for internal management and periodic publishing of the user and content metadata profile specification as relevant to the Saracen project.

### Design principles

* *TBD*

### Publishing Protocol

An initial specification draft will be created, beginning with version 0.1. That draft will evolve continually, with minor release numbers which reflect each published version and major release numbers which coincide with milestone releases.

When a release is published, two things will happen. Firstly, the public documentation for the given release will be published to the website. Secondly, a validation rule set will be made available to the API validator, which can be used to prove or disprove the conformance of a given request against the given release.

We need a protocol for organizing release dates and milestones. Either we organize regular teleconferences to agree upon the release dates, or else releases will be published periodically when the WP leader has determined that a suitable number of fields have reached stability.

### Formatting and Generation of Documentation

#### Standardization

In researching JSON formats for linked data exchange, two useful resources for writing specifications and other documentation were revealed:

1. [ReSpec.js, a tool that helps with specification editing primarily within a W3C context.](http://dev.w3.org/2009/dap/ReSpec.js/documentation.html)
    * This is a tool, currently in use for Mark Birbeck's [JSON-LD](http://json-ld.org/spec/latest/) among other specifications, aims to simplify the specification formatting and layout process and automatically generates a format which conforms to the W3C standards. It's worth looking in to how much work it would be to use this for the [Kendra Saracen Metadata API](http://live.saracen.kendra.org/) generator, either as a Drupal theme or module.
    * see also [this presentation of ReSpec.js](http://berjon.com/slides/20091104-respec/_respec.html)
1. [Web IDL](http://dev.w3.org/2006/webapi/WebIDL/)
    *  Web IDL is an IDL variant with a number of features that allow the behavior of common script objects in the web platform to be specified more readily. How interfaces described with Web IDL correspond to constructs within ECMAScript and Java execution environments is also detailed.

#### Export of supplementary documentation

* *TBD*
            
### Contents of the Specification

Any release of the specification contains multiple schemas which are used to represent domains of profile data. A specification release inherits the schemas linked to the previous release of that spec. Schemas contain one or more fields which contain the actual profile data and preferences. Every field has a machine-readable unique identifier (ID) which is used to distinguish it. The ID of a field with a status of `stable` SHOULD NOT be modified.

*TBD*: give a bullet-point sketch over the format of the API documentation in terms of methods, parameters, and responses.

*TBD*: Where does the user's privacy (defaults and preferences) come to be defined? Does that fit within the storage structure (schema or field) or within the transport?

*TBD*: determine in general what kinds of methods and schemas will take priority for updates and requests when the system is under load.

### License

Sample code and the validation tool will be released under the GNU General Public License. Additionally, Kendra will Creative Commons license all of the API documentation, so users will be welcome to reuse and remix as appropriate.

### The Publishing System

* `saracen.kendra.org` will host the live *Kendra Saracen Trial*, containing all the live trial code, the *Kendra Saracen Metadata API* and the API's collaborative modeling/building system.
* Like an Intranet or publishing tool, provides a form for Saracen consortium members to view the current version of the specification and propose changes for inclusion in the next published version of the specification.
* This allows Kendra to export a version of the specification for implementation as a web service.
* We create new content types on the site, to store the Saracen profile specification Containers and Attributes.
    * Adopt a simple but powerful model where a *field can either a element or point to a Container of elements* and these Containers can be nested.
        * The system should monitor for circular references before changes are saved.
    * Values for all fields are REQUIRED unless otherwise specified.
* CMS publishing data structure
    * Container
        * container ID (machine-readable) (could be a schema identifier e.g. `user`, `video`, `audio`, `event`)
        * release number (numeric string with decimal delimiter)
        * is root (only true for the base Container, i.e. the main specification)
        * status [`stable`, `testing`, `unstable`, `deprecated`]
        * cardinality [`single`, `multiple`]
        * privacy [`private`, `protected`, `public`]
        * label (human-readable, English)
        * description (English)
        * baseURI (machine-readable URI for an ontology; OPTIONAL)
    * Attribute
        * container ID (only one per field)
        * field ID (machine-readable)
        * data type
            * `string` (allowed values: UTF-8 encoded string, maximum length TBD)
            * `bool` (allowed values: 0 = False, 1 = true)
            * `enum` (allowed values: defined in the "allowed values" field)
            * `numeric` (allowed values: signed integer or floating point numbers; maximum value TBD)
            * `datetime` (allowed values: [RFC 3339](http://tools.ietf.org/html/rfc3339) formatted date-time field)
                * various formatting standards include
                    * [ISO 8601](http://www.iso.org/iso/catalogue_detail?csnumber=40874)
                    * [Date and Time Specification: RFC-822 Section 5](http://tools.ietf.org/html/rfc822#section-5) format, which is the standard for Javascript (ECMAScript)
                    * [RFC 3339: Date and Time on the Internet: Timestamps](http://tools.ietf.org/html/rfc3339) format, which is a profile of ISO 8601 and is the [standard for OpenSocial](http://opensocial-resources.googlecode.com/svn/spec/1.0/Core-Data.xml#RFC3339)
                * may need to include Javascript date parse and formatting functions in the library
        * allowed values (machine-readable, used for `enum` data type; OPTIONAL)
        * default value (OPTIONAL)
        * status [`stable`, `testing`, `unstable`, `deprecated`]
        * privacy [`private`, `protected`, `public`]
        * label (human-readable, English)
        * description (English)
* Base Profile
    * [Field definitions from the OpenSocial 1.0 specification](http://atrium.kendra.org.uk/sites/default/files/opensocial-profile-fields.csv) will be used to create a base profile on which to create the specification.
    * [Additional categories inferred from the four proposed scenarios and derived from the results of the survey](http://atrium.kendra.org.uk/sites/default/files/opensocial-profile-additional-fields.csv) can then be added to the base profile, and can be used to extend the specification via the use of [protocol extensions](http://opensocial-resources.googlecode.com/svn/spec/1.0/OpenSocial-Specification.xml).
* Authentication
    * *ideally, could use OAuth to link a foreign SNS account, import profile metadata, and create a Saracen profile*
    * OPTIONAL: single sign-on (via Drupal Bakery) - perhaps a good thing. Only want to hand out one Kendra profile to each Saracen project member, otherwise it'll get messy.
        * Single sign-on would be beneficial for us (the Kendra developers), although it wouldn't make any difference for other participants, who would not have special roles on any of the other servers.
        * Alternatively we could import the list of users into the Kendra LDAP directory and use that for authentication. Saracen partners who wish to contribute to the specification would be given a role (LDAP group membership) like "Saracen API Editor", whereas trialists would be given a role (LDAP group) like "Saracen tester". To be determined: whether this would make it easier or more complex to manage users this way in the long term.
* Hosting
    * GitHub repository: https://github.com/kendrainitiative/kendra_saracen_trial
    * The following domains are set up and pointing to FUN (`kendra.org`):
        * `saracen.kendra.org`
        * `dev.saracen.kendra.org`
        * `test.saracen.kendra.org`
        * `live.saracen.kendra.org`

### Version management

* *TBD*

### Validation of data input for conformance to a given version of the specification

* *TBD*

* see [CERNY project](http://www.cerny-online.com/cerny.js/documentation/schema/) and [JSON Schema]

### References

* [RFC2119] Bradner, S., “Key words for use in RFCs to Indicate Requirement Levels”, RFC 2119, March 1997.

### See also

* http://www.freebase.com/docs/topic_api
* http://code.google.com/apis/opensocial/docs/0.8/reference/#opensocial.Enum
